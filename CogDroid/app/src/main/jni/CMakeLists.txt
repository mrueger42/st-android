cmake_minimum_required(VERSION 3.4.1)

set(vmName StackVM)
#project(CogSpurAndroidVM)
project(${vmName})

set(CMAKE_CONFIGURATION_TYPES Debug)

  include (TestBigEndian)

  TEST_BIG_ENDIAN (WORDS_BIGENDIAN)
  IF (WORDS_BIGENDIAN)
    SET (MSB_FIRST 1)
  ELSE ()
    SET (LSB_FIRST 1)
  ENDIF (WORDS_BIGENDIAN)

include(directories.cmake)

add_definitions(
	-DANDROID
	-DVM_TARGET_OS="android"
	-DVM_TARGET_CPU="armeabi-v7a"
 	-DNOEXECINFO
	-DAVOID_OPENGL_H
	-DFT2_BUILD_LIBRARY
	-DVM_TICKER=1

	-DUSE_GLOBAL_STRUCT=0
	-DITIMER_HEARTBEAT=1
	-DSPURVM
	-D_GNU_SOURCE
	-DNDEBUG
	-DCOGMTVM=0
#	-DDEBUGVM=0
	-DLSB_FIRST=1
#	-DNO_VM_PROFILE=1

#	-g0 -O2
	-g
	-m32
	)


include_directories(
	${platformsDir}/${androidTarget}/vm
	${platformsDir}/unix/vm
	${platformsDir}/Cross/vm
	${srcDir}/vm
	${buildDir}
	)

add_custom_command(OUTPUT version.c
		COMMAND ${platformsDir}/unix/config/verstamp version.c gcc
		COMMENT "Generating version.c"
	)

set(coreSources
	${srcVMDir}/cogit.c
	${srcVMDir}/gcc3x-cointerp.c
	)

# set_source_files_properties (${srcVMDir}/cogit.c PROPERTIES COMPILE_FLAGS "-m32 -msse2 -O2")
set_source_files_properties (${srcVMDir}/cogit.c PROPERTIES COMPILE_FLAGS "-g -m32")

# set_source_files_properties (${targetPlatform}/vm/sqUnixHeartbeat.c PROPERTIES COMPILE_FLAGS "-m32 -msse2 -O2")

set(platformVMSources
	${platformsDir}/${androidTarget}/vm/sqAndroid.c
# 	${platformsDir}/${androidTarget}/vm/sqAndroidLogger.c

	${platformsDir}/unix/vm/aio.c
	${platformsDir}/unix/vm/debug.c
	${platformsDir}/unix/vm/osExports.c
	${platformsDir}/unix/vm/sqUnixCharConv.c
	${platformsDir}/unix/vm/sqUnixExternalPrims.c
	${platformsDir}/unix/vm/sqUnixITimerTickerHeartbeat.c
	${platformsDir}/unix/vm/sqUnixMain.c
	${platformsDir}/unix/vm/sqUnixMemory.c
	${platformsDir}/unix/vm/sqUnixSpurMemory.c
	${platformsDir}/unix/vm/sqUnixThreads.c
	${platformsDir}/unix/vm/sqUnixVMProfile.c
	)

set(crossVMSources
	${crossDir}/vm/sqHeapMap.c
	${crossDir}/vm/sqTicker.c
	${crossDir}/vm/sqExternalSemaphores.c
	${crossDir}/vm/sqNamedPrims.c
	${crossDir}/vm/sqVirtualMachine.c
	)

set(extraSources version.c)

add_library(
	# Specifies the name of the library.
	${vmName}

	# Sets the library as a shared library.
	SHARED

	${coreSources}
	${crossVMSources}
	${platformVMSources}
	${extraSources}
	)

set_target_properties(${vmName} PROPERTIES LINKER_LANGUAGE C)

set_target_properties(${vmName} PROPERTIES LINK_FLAGS "-m32")

find_library(
	# Defines the name of the path variable that stores the
	# location of the NDK library.
	log-lib

	# Specifies the name of the NDK library that
	# CMake needs to locate.1
	log
	)

list(APPEND LINKLIBS m)
list(APPEND LINKLIBS dl)

# set(EXECUTABLE_OUTPUT_PATH "${outputDir}")

# add_subdirectory("${buildDir}/AndroidPlugin")
add_subdirectory("${buildDir}/BitBltPlugin")
add_subdirectory("${buildDir}/FilePlugin")
add_subdirectory("${buildDir}/FloatMathPlugin")
add_subdirectory("${buildDir}/LargeIntegers")
add_subdirectory("${buildDir}/Matrix2x3Plugin")
add_subdirectory("${buildDir}/MiscPrimitivePlugin")
# add_subdirectory("${buildDir}/SocketPlugin")


add_subdirectory("${buildDir}/vm-display-android")
add_subdirectory("${buildDir}/vm-display-null")

add_subdirectory("${buildDir}/vm-sound-null")

target_link_libraries(${vmName}
	BitBltPlugin
	FilePlugin
	FloatMathPlugin
	LargeIntegers
	Matrix2x3Plugin
	MiscPrimitivePlugin
#	SocketPlugin
	)

target_link_libraries(${vmName}
	${log-lib}
	${LINKLIBS}
	)
