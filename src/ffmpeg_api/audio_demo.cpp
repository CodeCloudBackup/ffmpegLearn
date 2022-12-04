#include "audio_demo.h"

void OpenAudio(void)
{
	AVFormatContext *fmtContext = nullptr;
	AVDictionary *option = nullptr;
	char errors[1024];
	int ret = 0;
	avdevice_register_all();
	av_log_set_level(AV_LOG_DEBUG);
	av_log(NULL, AV_LOG_DEBUG, "start demo ...\n");
	std::string deviceName = "hw:0";
	//mac:avfoundation linux:alsa
	AVInputFormat *iformat = const_cast<AVInputFormat *> (av_find_input_format("alsa"));
	if ((ret = avformat_open_input(&fmtContext, deviceName.c_str(), iformat, &option)) < 0) {
		av_strerror(ret, errors, 1024);
		printf( "Fialed to open audio devuice [%d]%s\n",ret, errors);
		return;
	}

	while (1);
}
