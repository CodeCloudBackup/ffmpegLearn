#include "video_play.h"
#include <QDebug>
#include <QDateTime>

VideoPlay::VideoPlay(QObject *parent)
    : QObject(parent),
    m_pAVFormatContext(nullptr),
    m_pAVCodecContext(nullptr),
    m_pAVFrame(nullptr),
    m_pSwsContext(nullptr),
    m_videoWidth(0),
    m_videoHeight(0),
    m_videoStreamIndex(-1),
    m_stopped(0)
{


}


/// 初始化
bool VideoPlay::Init(){
    /// rtsp:
    //初始化网络流格式,使用RTSP网络流时必须先执行
    avformat_network_init();
    //申请一个AVFormatContext结构的内存,并进行简单初始化
    m_pAVFormatContext = avformat_alloc_context();
    m_pAVFrame = av_frame_alloc();
    //打开视频流
    int result = avformat_open_input(
                &m_pAVFormatContext, m_url.toStdString().c_str(), NULL, NULL);
    CHECK_RESULT_RETURN(result<0, false,"open video failed " );
    //获取视频流信息
    result = avformat_find_stream_info(m_pAVFormatContext, NULL);
    CHECK_RESULT_RETURN(result<0, false, "find video strean failed .");

    //获取视频流索引
    m_videoStreamIndex = -1;
    for (int i = 0; i < m_pAVFormatContext->nb_streams; i++) {
        if (m_pAVFormatContext->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO) {
            m_videoStreamIndex = i;
            break;
        }
    }
    CHECK_RESULT_RETURN(m_videoStreamIndex == -1, false, "Get video Stream failed.");

    /// 分析编解码器的详细信息
    m_pAVCodecContext = m_pAVFormatContext->streams[m_videoStreamIndex]->codec;
    m_videoWidth = m_pAVCodecContext->width;
    m_videoHeight = m_pAVCodecContext->height;
    /// 分配AVPicture：RGB24
    avpicture_alloc(&m_pAVPicture,AV_PIX_FMT_RGB24,m_videoWidth,m_videoHeight);

    /// decoder:
    AVCodec *pAVCodec = NULL;
    //获取视频流解码器
    pAVCodec = avcodec_find_decoder(m_pAVCodecContext->codec_id);// eg: h264,h265

    /// color space convert:  SwsContext
    /// sws_getContext, sws_freeContext, sws_scale(...)
    m_pSwsContext = sws_getContext(
                m_videoWidth,m_videoHeight,AV_PIX_FMT_YUV420P,
                m_videoWidth,m_videoHeight,AV_PIX_FMT_RGB24,
                SWS_BICUBIC,0,0,0);

    //打开对应解码器
    result = avcodec_open2(m_pAVCodecContext,pAVCodec,NULL);
    CHECK_RESULT_RETURN(result<0, false, "open decode failed.");
    qDebug()<<"初始化视频流成功 ";
    return true;
}


void VideoPlay::Deinit(){
    avformat_network_deinit();

    av_frame_free(&m_pAVFrame);
    m_pAVFrame = nullptr;
    if (m_pAVFormatContext)
    {
        avformat_free_context(m_pAVFormatContext);
        m_pAVFormatContext = nullptr;
    }
    avpicture_free(&m_pAVPicture);
    if(m_pSwsContext) {
        sws_freeContext(m_pSwsContext);
        m_pSwsContext = nullptr;
    }
}


/// 开始读取网络摄像头，解封装、解码，预览
void VideoPlay::Play(){
    int ret = -1;
    while(1){
        if(m_stopped){
            qDebug() << "Stop play video";
            break;
        }
        if (av_read_frame(m_pAVFormatContext, &m_pAVPacket) >= 0){
            if(m_pAVPacket.stream_index == m_videoStreamIndex){
                qDebug()<<"start decode "<<QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss ");

                /* send the packet with the compressed data to the decoder */
                ret = avcodec_send_packet(m_pAVCodecContext, &m_pAVPacket);
                if (ret < 0)
                {
                    fprintf(stderr, "Error submitting the packet to the decoder\n");
                    continue;
                }

                ret = avcodec_receive_frame(m_pAVCodecContext, m_pAVFrame);
                if (ret == AVERROR(EAGAIN) || ret == AVERROR_EOF)
                    continue;

                if (ret >= 0){///frameFinished
                    m_mutex.lock();
                    sws_scale(m_pSwsContext,(const uint8_t* const *)m_pAVFrame->data,m_pAVFrame->linesize, \
                              0,m_videoHeight,m_pAVPicture.data,m_pAVPicture.linesize);
                    //发送获取一帧图像信号
                    QImage image(m_pAVPicture.data[0],m_videoWidth,m_videoHeight,QImage::Format_RGB888);
                    emit GetImage(image);
                    m_mutex.unlock();
                }
                /// -re  ： 帧率
                QThread::msleep(33);
            }
        }
        //释放资源,否则内存会一直上升
        av_free_packet(&m_pAVPacket);
    }
    return;
}
