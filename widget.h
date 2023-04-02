#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include <QPoint>
#include <QPushButton>
#include "ffmpeg_c.h"
#include "video_label.h"
#include "video_play.h"
#include "video_thread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void RemoveLayout();
private:
    Ui::Widget *ui;
    int m_curComboxIndex;
    QVector<VideoLabel*> m_pLabelVector;
    QVector<VideoPlay*> m_pVideoPlayVector; //私有成员变量
    QVector<VideoThread*> m_pVideoThreadVector;
    QVector<uint32_t> m_VideoChannelStatus;
private slots:
    void on_comboBox_2_currentIndexChanged(int index);
     void SetImage1(const QImage &image);
     void on_pushButton_Start_clicked();
     void on_pushButton_Stop_clicked();
     void on_comboBox_activated(int index);
};
#endif // WIDGET_H
