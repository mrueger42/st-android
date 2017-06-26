/* sqAndroid.c
 * Initialize the VM here. In order to do this, call interp_init (formerly main) with
 * the zeroth argument pointing to the image plus some fake executable name. This will
 * give the VM an idea where the image is.
 *
 *   Copyright (C) 2010-2017 by
 *   Andreas Raab, Jean Baptiste Arnaud, Santiago Bragagnolo, Dmitry Golubovsky, Michael Rueger
 *   All rights reserved.
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a
 *   copy of this software and associated documentation files (the "Software"),
 *   to deal in the Software without restriction, including without limitation
 *   the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *   and/or sell copies of the Software, and to permit persons to whom the
 *   Software is furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in
 *   all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *   DEALINGS IN THE SOFTWARE.
 */

#include <stdio.h>
#include <fcntl.h>
#include <pthread.h>

#include <android/log.h>
#include <unistd.h>

static int pfd[2];
static pthread_t thr;
static const char *tag = "jni-vm";

void jnilog(char *str) {
	__android_log_write(ANDROID_LOG_DEBUG, tag, str);
}
int jnilogf(const char *fmt, ...) {
	int result;
	va_list args;
	va_start(args, fmt);
	result = __android_log_vprint(ANDROID_LOG_INFO, tag, fmt, args);
//	char str[10000];
//	vsnprintf(str, 9999, fmt, args);
//	jnilog(str);
	va_end(args);
	return result;
}

int sdprintf(const char *fmt, ...) {
	int result;
	va_list args;
	va_start(args, fmt);
	result = __android_log_vprint(ANDROID_LOG_INFO, "Smalltalk", fmt, args);
//	char str[10000];
//	vsnprintf(str, 9999, fmt, args);
//	jnilog(str);
	va_end(args);
	return result;
}

int primNativeLog(char *fmt) {
	return sdprintf(fmt);
}

/*
 * the following is based on
 * https://codelab.wordpress.com/2014/11/03/how-to-use-standard-output-streams-for-logging-in-android-apps/
 */
static void *thread_func(void *ignore)
{
	ssize_t rdsz;
	char buf[128];
	while((rdsz = read(pfd[0], buf, sizeof buf - 1)) > 0) {
		if(buf[rdsz - 1] == '\n') --rdsz;
		buf[rdsz] = 0;  /* add null-terminator */
		// priority one from enum android_LogPriority
		__android_log_write(ANDROID_LOG_DEBUG, tag, buf);
	}
	return 0;
}

//int start_logger(const char *app_name) {
//	tag = app_name;

int start_logger() {

	/* make stdout line-buffered and stderr unbuffered */
	setvbuf(stdout, 0, _IOLBF, 0);
	setvbuf(stderr, 0, _IONBF, 0);

	/* create the pipe and redirect stdout and stderr */
	pipe(pfd);
	dup2(pfd[1], 1);
	dup2(pfd[1], 2);

	/* spawn the logging thread */
	if(pthread_create(&thr, 0, thread_func, 0) == -1)
		return -1;
	pthread_detach(thr);
	return 0;
}

