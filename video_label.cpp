#include "video_label.h"

VideoLabel::VideoLabel(QWidget *parent)
    : QLabel(parent)
{

}

VideoLabel::~VideoLabel()
{
    if(m_enterPixmap) {
        delete m_enterPixmap;
        m_enterPixmap = nullptr;
    }
    if(m_leavePixmap) {
        delete m_leavePixmap;
        m_leavePixmap = nullptr;
    }
}

bool VideoLabel::InitPixmap()
{
    QSize labelSize(320, 190);
    m_enterPixmap = new QPixmap(":/image/camera/lab_hover.png");
    m_enterPixmap->scaled(labelSize);
    m_leavePixmap = new QPixmap(":/image/camera/lab_normal.png");
    m_leavePixmap->scaled(labelSize);
    return true;
}

void VideoLabel::enterEvent(QEvent* event)
{
    this->setPixmap(*m_enterPixmap);

}

void VideoLabel::leaveEvent(QEvent* event)
{
    this->setPixmap(*m_leavePixmap);
}
