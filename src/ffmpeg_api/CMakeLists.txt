FILE(GLOB source ./*.cpp)
SET(FFMPEG_LIB  
	 avutil
	 avdevice
	 avformat
	)

ADD_LIBRARY(ffmpeg_api SHARED ${source})

TARGET_LINK_LIBRARIES(ffmpeg_api ${FFMPEG_LIB})
#Á¬½Ó¿â