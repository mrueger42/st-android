set(topDir "${CMAKE_SOURCE_DIR}/")

set(buildDir "${topDir}/build")

set(srcDir "${topDir}/src")
set(srcPluginsDir "${srcDir}/plugins")

# set(srcVMDir "${srcDir}/vm")
set(srcVMDir "${srcDir}/vm")

set(platformsDir "${topDir}/platforms")
set(crossDir "${platformsDir}/Cross")

set(androidTarget "android")
set(platformName "unix")
set(targetPlatformDir ${platformsDir}/${platformName})
set(platformVMDir "${targetPlatform}/vm")

set(outputDir "${topDir}/results")
