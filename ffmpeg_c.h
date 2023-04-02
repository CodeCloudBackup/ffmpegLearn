#ifndef FFMPEG_C_H
#define FFMPEG_C_H

extern "C"{
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libavfilter/avfilter.h>
    #include <libswscale/swscale.h>
    #include <libavutil/frame.h>
};

#undef main

#endif // FFMPEG_C_H
