/****************************************************************************
*   PROJECT: Android event-driven beat logic for Stack VM
*   FILE:    sqAndroidEvtBeat.c
*   CONTENT: 
*
*   AUTHOR:  Dmitry Golubovsky, based on Eliot Miranda's heartbeat code
*   ADDRESS: 
*   EMAIL:   golubovsky@gmail.com
*   RCSID:   $Id$
*
*   NOTES: 
*
*****************************************************************************/

#include "sq.h"
#include "sqAssert.h"
#include "sqMemoryFence.h"
#include "sqAndroidEvtBeat.h"
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <sys/time.h>

#define SecondsFrom1901To1970      2177452800ULL
#define MicrosecondsFrom1901To1970 2177452800000000ULL

#define MicrosecondsPerSecond 1000000ULL
#define MillisecondsPerSecond 1000ULL

#define MicrosecondsPerMillisecond 1000ULL

# define DEFAULT_BEAT_MS 2

static unsigned volatile long long utcMicrosecondClock;
static unsigned volatile long long localMicrosecondClock;
static unsigned long long utcStartMicroseconds; /* for the ioMSecs clock. */
static long long vmGMTOffset = 0;
static unsigned long long frequencyMeasureStart = 0;
static unsigned long heartbeats;

# define logusecs(usecs) 0
# define logmsecs(msecs) 0

#define microToMilliseconds(usecs) ((((usecs) - utcStartMicroseconds) \
									/ MicrosecondsPerMillisecond) \
									& MillisecondClockMask)


/* Compute the current VM time basis, the number of microseconds from 1901. */

static unsigned long long
currentUTCMicroseconds()
{
	struct timeval utcNow;

	gettimeofday(&utcNow,0);
	return ((utcNow.tv_sec * MicrosecondsPerSecond) + utcNow.tv_usec)
			+ MicrosecondsFrom1901To1970;
}

usqLong
ioUTCMicroseconds() {return currentUTCMicroseconds();}

usqLong
ioLocalMicroseconds() 
{
	return currentUTCMicroseconds() + vmGMTOffset;
}
	

/* This is an expensive interface for use by profiling code that wants the time
 * now rather than as of the last heartbeat.
 */
usqLong
ioUTCMicrosecondsNow() { return currentUTCMicroseconds(); }

int
ioMSecs() { return  microToMilliseconds(currentUTCMicroseconds()); }

sqLong
ioHighResClock(void)
{
  /* return the value of the high performance counter */
  sqLong value = 0LL;
#if defined(__GNUC__) && ( defined(i386) || defined(__i386) || defined(__i386__)  \
			|| defined(i486) || defined(__i486) || defined (__i486__) \
			|| defined(intel) || defined(x86) || defined(i86pc) )
    __asm__ __volatile__ ("rdtsc" : "=A"(value));
#else
  /* use clock_gettime instead */
  struct timespec ts;
  int rc = clock_gettime(CLOCK_MONOTONIC, &ts);
  if (rc <= 0) {
    return 0;
  }
  value = ts.tv_sec * 1000LL + ts.tv_nsec / 1000000LL;
#endif
  return value;
}

static unsigned int   lowResMSecs= 0;
static struct timeval startUpTime;

static void
updateMicrosecondClock()
{
	unsigned long long newUtcMicrosecondClock;
	unsigned long long newLocalMicrosecondClock;

	newUtcMicrosecondClock = currentUTCMicroseconds();

	/* The native clock may go backwards, e.g. due to NTP adjustments, although
	 * why it can't avoid small backward steps itself, I don't know.  Simply
	 * ignore backward steps and wait until the clock catches up again.  Of
	 * course this will cause problems if the clock is manually adjusted.  To
	 * which the doctor says, "don't do that".
	 */
	if (!asserta(newUtcMicrosecondClock >= utcMicrosecondClock)) {
		logusecs(0); /* if logging log a backward step as 0 */
		return;
	}
	newLocalMicrosecondClock = newUtcMicrosecondClock + vmGMTOffset;

	set64(utcMicrosecondClock,newUtcMicrosecondClock);
	set64(localMicrosecondClock,newLocalMicrosecondClock);

	logusecs(newUtcMicrosecondClock);
}


/*
 * Answer the millisecond clock as computed on Unix prior to the 64-bit
 * microsecond clock.  This is to help verify that the new clock is correct.
 */
sqInt
ioOldMSecs(void)
{
  struct timeval now;
  unsigned int nowMSecs;

#if 1 /* HAVE_HIGHRES_COUNTER */

  /* if we have a cheap, high-res counter use that to limit
     the frequency of calls to gettimeofday to something reasonable. */
  static unsigned int baseMSecs = 0;      /* msecs when we took base tick */
  static sqLong baseTicks = 0;/* base tick for adjustment */
  static sqLong tickDelta = 0;/* ticks / msec */
  static sqLong nextTick = 0; /* next tick to check gettimeofday */

  sqLong thisTick = ioHighResClock();

  if(thisTick < nextTick) return lowResMSecs;

#endif

  gettimeofday(&now, 0);
  if ((now.tv_usec-= startUpTime.tv_usec) < 0)
    {
      now.tv_usec+= 1000000;
      now.tv_sec-= 1;
    }
  now.tv_sec-= startUpTime.tv_sec;
  nowMSecs = (now.tv_usec / 1000 + now.tv_sec * 1000);

#if 1 /* HAVE_HIGHRES_COUNTER */
  {
    unsigned int msecsDelta;
    /* Adjust our rdtsc rate every 10...100 msecs as needed.
       This also covers msecs clock-wraparound. */
    msecsDelta = nowMSecs - baseMSecs;
    if(msecsDelta < 0 || msecsDelta > 100) {
      /* Either we've hit a clock-wraparound or we are being
	 sampled in intervals larger than 100msecs.
	 Don't try any fancy adjustments */
      baseMSecs = nowMSecs;
      baseTicks = thisTick;
      nextTick = 0;
      tickDelta = 0;
    } else if(msecsDelta >= 10) {
      /* limit the rate of adjustments to 10msecs */
      baseMSecs = nowMSecs;
      tickDelta = (thisTick - baseTicks) / msecsDelta;
      nextTick = baseTicks = thisTick;
    }
    nextTick += tickDelta;
  }
#endif
  return lowResMSecs= nowMSecs;
}

static int beatMilliseconds = DEFAULT_BEAT_MS;
static struct timespec beatperiod = { 0, DEFAULT_BEAT_MS * 1000 * 1000 };

int
ioHeartbeatMilliseconds() { return beatMilliseconds; }

/* Note: ioMicroMSecs returns *milli*seconds */
int ioMicroMSecs(void) { return microToMilliseconds(currentUTCMicroseconds()); }

/* returns the local wall clock time */
int
ioSeconds(void) { return ioLocalMicroseconds() / MicrosecondsPerSecond; }

void
ioInitTime(void)
{
	ioUpdateVMTimezone(); /* does updateMicrosecondClock as a side-effect */
	updateMicrosecondClock(); /* this can now compute localUTCMicroseconds */
	utcStartMicroseconds = currentUTCMicroseconds();
#if !macintoshSqueak
	/* This is only needed for ioOldMSecs */
	gettimeofday(&startUpTime, 0);
#endif
}

void
ioUpdateVMTimezone()
{
	time_t utctt;
	updateMicrosecondClock();
	utctt = (get64(utcMicrosecondClock) - MicrosecondsFrom1901To1970)
				/ MicrosecondsPerSecond;
	vmGMTOffset = localtime(&utctt)->tm_gmtoff * MicrosecondsPerSecond;
}

void
ioGetClockLogSizeUsecsIdxMsecsIdx(sqInt *np, void **usecsp, sqInt *uip, void **msecsp, sqInt *mip)
{
	*np = *uip = *mip = 0;
	*usecsp = *msecsp = 0;
}


/* Answer the average heartbeats per second since the stats were last reset.
 */
unsigned long
ioHeartbeatFrequency(int resetStats)
{
	unsigned duration = (ioUTCMicroseconds() - get64(frequencyMeasureStart))
						/ MicrosecondsPerSecond;
	unsigned frequency = duration ? heartbeats / duration : 0;

	if (resetStats) {
		unsigned long long zero = 0;
		set64(frequencyMeasureStart,zero);
	}
	return frequency;
}

void
ioSetHeartbeatMilliseconds(int ms)
{
	beatMilliseconds = ms;
	beatperiod.tv_sec = beatMilliseconds / 1000;
	beatperiod.tv_nsec = (beatMilliseconds % 1000) * 1000 * 1000;
}

void
ioSynchronousCheckForEvents()
{
}

void
addHighPriorityTickee()
{
}

void
addSynchronousTickee()
{
}

void
heartbeat()
{
	int saved_errno = errno;
	updateMicrosecondClock();
	if (get64(frequencyMeasureStart) == 0) {
		set64(frequencyMeasureStart,utcMicrosecondClock);
		heartbeats = 0;
	}
	else
		heartbeats += 1;
	forceInterruptCheckFromHeartbeat();

	errno = saved_errno;
}

