#ifndef __AUDIO_DEMO_H
#define __AUDIO_DEMO_H
#include <iostream>
#include <string>
extern"C" {
#include "libavutil/avutil.h"
#include "libavdevice/avdevice.h"
#include "libavformat/avformat.h"
}
void OpenAudio(void);
#endif