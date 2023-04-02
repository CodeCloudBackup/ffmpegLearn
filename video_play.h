#ifndef VIDEOPLAY_H
#define VIDEOPLAY_H

#include <QObject>
#include <QMutex>
#include <QImage>
#include <QThread>
#include "ffmpeg_c.h"
#include "common.h"

class VideoPlay : public QObject
{
    Q_OBJECT
public:
    explicit VideoPlay(QObject *parent = nullptr);
    bool Init();
    void Play();
    void Deinit();

    void SetUrl(QString url){this->m_url=url;}
    QString Url()const{return m_url;}
    int VideoWidth()const{ return m_videoWidth; }
    int VideoHeight()const{return m_videoHeight;}
    void SetStopped(int st){ this->m_stopped = st; }

    /// declare member variables:
private:
    QMutex m_mutex;
    AVFormatContext *m_pAVFormatContext;
    AVCodecContext *m_pAVCodecContext;
    AVFrame *m_pAVFrame;
    SwsContext * m_pSwsContext;
    AVPacket m_pAVPacket;
    AVPicture  m_pAVPicture;

    QString m_url;
    int m_videoWidth;
    int m_videoHeight;
    int m_videoStreamIndex;

    int m_stopped;
signals:
    void GetImage(const QImage &image);
};

#endif // VIDEOPLAY_H
