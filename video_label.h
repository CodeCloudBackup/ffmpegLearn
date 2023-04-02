#ifndef VIDEOLABEL_H
#define VIDEOLABEL_H

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QEvent>
#include <QPixmap>
class VideoLabel : public QLabel
{
    Q_OBJECT
    QPixmap *m_enterPixmap;
    QPixmap *m_leavePixmap;
public:
    explicit VideoLabel(QWidget *parent = nullptr);
    virtual ~VideoLabel();
    bool InitPixmap();
signals:
    void clieck();
protected:
    virtual void enterEvent(QEvent* event);
    virtual void leaveEvent(QEvent* event);
};

#endif // VIDEOLABEL_H
