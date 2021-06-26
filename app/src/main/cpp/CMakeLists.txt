# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)

# Declares and names the project.

project("ffmpegtest")

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
        native-lib

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        native-lib.cpp )

set(JNI_LIBS_DIR ${CMAKE_SOURCE_DIR}/../ffmpeg)

add_library(avutil
        SHARED
        IMPORTED )
set_target_properties(avutil
        PROPERTIES IMPORTED_LOCATION
        ${JNI_LIBS_DIR}/${ANDROID_ABI}/lib/libavutil.so )

add_library(avresample
        SHARED
        IMPORTED )
set_target_properties(avresample
        PROPERTIES IMPORTED_LOCATION
        ${JNI_LIBS_DIR}/${ANDROID_ABI}/lib/libavresample.so )

add_library(swresample
        SHARED
        IMPORTED )
set_target_properties(swresample
        PROPERTIES IMPORTED_LOCATION
        ${JNI_LIBS_DIR}/${ANDROID_ABI}/lib/libswresample.so )

add_library(swscale
        SHARED
        IMPORTED )
set_target_properties(swscale
        PROPERTIES IMPORTED_LOCATION
        ${JNI_LIBS_DIR}/${ANDROID_ABI}/lib/libswscale.so )

add_library(avcodec
        SHARED
        IMPORTED )
set_target_properties(avcodec
        PROPERTIES IMPORTED_LOCATION
        ${JNI_LIBS_DIR}/${ANDROID_ABI}/lib/libavcodec.so )

add_library(avformat
        SHARED
        IMPORTED )
set_target_properties(avformat
        PROPERTIES IMPORTED_LOCATION
        ${JNI_LIBS_DIR}/${ANDROID_ABI}/lib/libavformat.so )

add_library(avfilter
        SHARED
        IMPORTED )
set_target_properties(avfilter
        PROPERTIES IMPORTED_LOCATION
        ${JNI_LIBS_DIR}/${ANDROID_ABI}/lib/libavfilter.so )

add_library(avdevice
        SHARED
        IMPORTED )
set_target_properties(avdevice
        PROPERTIES IMPORTED_LOCATION
        ${JNI_LIBS_DIR}/${ANDROID_ABI}/lib/libavdevice.so )

include_directories(${JNI_LIBS_DIR}/${ANDROID_ABI}/include)

target_link_libraries(native-lib
        avutil swresample swscale avcodec avformat avfilter
        log ${android-lib} )