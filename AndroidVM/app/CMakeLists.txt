# Sets the minimum version of CMake required to build your native library.
# This ensures that a certain set of CMake features is available to
# your build.

cmake_minimum_required(VERSION 3.4.1)

# Specifies a library name, specifies whether the library is STATIC or
# SHARED, and provides relative paths to the source code. You can
# define multiple libraries by adding multiple add.library() commands,
# and CMake builds them for you. When you build your app, Gradle
# automatically packages shared libraries with your APK.

add_library( # Specifies the name of the library.
             squeakvm

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             src/main/jni/aio.c
             src/main/jni/B2DPlugin.c
             src/main/jni/BitBltPlugin.c
             src/main/jni/FilePlugin.c
             src/main/jni/interp.c
             src/main/jni/LargeIntegers.c
             src/main/jni/MiscPrimitivePlugin.c
             src/main/jni/SocketPlugin.c
             src/main/jni/sqExternalPrims.c
             src/main/jni/sqFilePluginBasicPrims.c
             src/main/jni/sqNamedPrims.c
             src/main/jni/squeakvm.c
             src/main/jni/sqUnixSocket.c
             src/main/jni/sqVirtualMachine.c
             src/main/jni/ZipPlugin.c
             )

# Specifies a path to native header files.
include_directories(src/main/jni/)

set_target_properties(squeakvm PROPERTIES LINKER_LANGUAGE C)

find_library( # Defines the name of the path variable that stores the
              # location of the NDK library.
              log-lib

              # Specifies the name of the NDK library that
              # CMake needs to locate.
              log )
# Links your native library against one or more other native libraries.
target_link_libraries( # Specifies the target library.
                       squeakvm

                       # Links the log library to the target library.
                       ${log-lib} )
