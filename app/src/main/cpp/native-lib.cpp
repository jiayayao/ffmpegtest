#include <jni.h>
#include <string>
#include <android/log.h>


extern "C" {
#include <libavformat/avformat.h>
}

void ffmpeg_log_output(void* ptr, int level, const char* fmt, va_list vl) {
    __android_log_print(ANDROID_LOG_INFO, "jiayayao", "[ffmpeg log]%s", fmt);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_ffmpegtest_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    av_log_set_callback(ffmpeg_log_output);
    AVFormatContext *pContext = avformat_alloc_context();
    avformat_open_input(&pContext, "http://devimages.apple.com/iphone/samples/bipbop/bipbopall.m3u8", nullptr, nullptr);
    avformat_find_stream_info(pContext, nullptr);
    std::string hello = "jiayayao";
    return env->NewStringUTF(hello.c_str());
}