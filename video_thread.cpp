#include "video_thread.h"

#include <QDebug>
VideoThread::VideoThread(QObject *parent)
: QThread(parent),
  m_pFmpgNetCamera(nullptr)
{
}

// run函数为Qthread函数，不可修改名称
void VideoThread::run(){
    if(m_pFmpgNetCamera){
        m_pFmpgNetCamera->Play();
    }
    qDebug()<<"Run over";
}

