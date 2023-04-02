#ifndef VIDEOTHREAD_H
#define VIDEOTHREAD_H

#include <QObject>
#include <QThread>
#include "video_play.h"

class VideoThread : public QThread
{
    Q_OBJECT
public:
    explicit VideoThread(QObject *parent = nullptr);
    void run();
    void SetVideoPlay(VideoPlay * pfmpg){ m_pFmpgNetCamera = pfmpg; }

private:
    VideoPlay *m_pFmpgNetCamera;

signals:
public slots:
};

#endif // VIDEOTHREAD_H
