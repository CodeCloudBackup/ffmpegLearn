
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::Widget),
      m_curComboxIndex(0)
{
    ui->setupUi(this);
    // 视频显示
    QSize labelSize(320, 190);
    QPixmap labelPixmap(":/image/camera/lab_normal.png");
        labelPixmap.scaled(labelSize);
        m_pLabelVector.push_back( ui->labelVideo1);
        m_pLabelVector.push_back( ui->labelVideo2);
        m_pLabelVector.push_back( ui->labelVideo3);
        m_pLabelVector.push_back( ui->labelVideo4);
        m_pLabelVector.push_back( ui->labelVideo5);
        m_pLabelVector.push_back( ui->labelVideo6);
        m_pLabelVector.push_back( ui->labelVideo7);
        m_pLabelVector.push_back( ui->labelVideo8);
        m_pLabelVector.push_back( ui->labelVideo9);

    for (auto label:m_pLabelVector) {
        label->setMinimumSize(labelSize);
        label->setPixmap(labelPixmap);
        label->InitPixmap();
        m_pVideoPlayVector.push_back(new VideoPlay(label));
        m_pVideoThreadVector.push_back(new VideoThread(this));
        m_VideoChannelStatus.push_back(0);
    }

     ui->pushButton_Start->setEnabled(true);
}

Widget::~Widget()
{
    QThread::msleep(500);

    for (auto play:m_pVideoPlayVector) {
           if(play) {
               play->Deinit();
               delete play;
               play = nullptr;
           }
    }

    for (auto vThread:m_pVideoThreadVector) {
           if(vThread) {
               delete vThread;
               vThread = nullptr;
           }
    }
    delete ui;
}

void Widget::RemoveLayout()
{

    for (auto label:m_pLabelVector) {
        ui->gridLayout_2->removeWidget(label);
        label->setVisible(false);
    }
}

void Widget::on_comboBox_2_currentIndexChanged(int index)
{
    RemoveLayout();
    qDebug() << "index == " << index;
    if (index == 0) {
        QSize labelSize(320, 190);
        for (auto label:m_pLabelVector) {
            ui->gridLayout_2->addWidget(label);
            label->setVisible(true);
            label->setMinimumSize(labelSize);
        }

    } else if (index == 1) {
        QSize labelSize(426, 253);
        ui->gridLayout_2->addWidget(m_pLabelVector[0],0,0);
        ui->gridLayout_2->addWidget(m_pLabelVector[1],0,1);
        ui->gridLayout_2->addWidget(m_pLabelVector[2],1,0);
        ui->gridLayout_2->addWidget(m_pLabelVector[3],1,1);
        m_pLabelVector[0]->setVisible(true);
        m_pLabelVector[0]->setMinimumSize(labelSize);
        m_pLabelVector[1]->setVisible(true);
        m_pLabelVector[1]->setMinimumSize(labelSize);
        m_pLabelVector[2]->setVisible(true);
        m_pLabelVector[2]->setMinimumSize(labelSize);
        m_pLabelVector[3]->setVisible(true);
        m_pLabelVector[3]->setMinimumSize(labelSize);
        ui->gridLayout_2->setSpacing(10);
    } else if (index == 2) {
         QSize labelSize(1280, 760);
         ui->gridLayout_2->addWidget(m_pLabelVector[0],0,0);
         m_pLabelVector[0]->setVisible(true);
         m_pLabelVector[0]->setMinimumSize(labelSize);
    } else {

    }
}

void Widget::on_pushButton_Start_clicked()
{
     qDebug() << "pushButton_Start index == " << m_curComboxIndex;
    QString rtspUrl = ui->lineEdit->text();
    m_pVideoPlayVector[m_curComboxIndex]->SetStopped(0);
    if(m_VideoChannelStatus[m_curComboxIndex] == 1) {
        qDebug() << "just Start before";
        return;
    }
    m_VideoChannelStatus[m_curComboxIndex] = 1;
    ui->pushButton_Start->setEnabled(false);
    ui->pushButton_Stop->setEnabled(true);

    /// 胆子要够大：：等着栽更头
    if (m_pVideoThreadVector[m_curComboxIndex]->isRunning()) {
        return;
    }

    if( m_pVideoPlayVector[m_curComboxIndex]){
        // init, play, deinit
         m_pVideoPlayVector[m_curComboxIndex]->SetUrl(rtspUrl);
         m_pVideoPlayVector[m_curComboxIndex]->Init();

        connect( m_pVideoPlayVector[m_curComboxIndex], SIGNAL(GetImage(QImage)), this, SLOT(SetImage1(QImage)));

        ///// start a new thread , to run decoding(rtsp)

        if(m_pVideoThreadVector[m_curComboxIndex]){
            m_pVideoThreadVector[m_curComboxIndex]->SetVideoPlay(m_pVideoPlayVector[m_curComboxIndex]);
            qDebug() << "m_pFmpgThread->start()";
            ///// pFmpgThread->run(); ///// error,
            m_pVideoThreadVector[m_curComboxIndex]->start();
        }
    }

}


void Widget::on_pushButton_Stop_clicked()
{

    qDebug() << "pushButton_Stop index == " << m_curComboxIndex;
    if(m_VideoChannelStatus[m_curComboxIndex] == 2) {
            qDebug() << "just Stop before";
            return;
    }

    m_VideoChannelStatus[m_curComboxIndex] = 2;
    ui->pushButton_Start->setEnabled(true);
    ui->pushButton_Stop->setEnabled(false);
    if(m_pVideoPlayVector[m_curComboxIndex]){
        m_pVideoPlayVector[m_curComboxIndex]->SetStopped(1);  /// stop camera
    }
    QThread::msleep(500);// sleep(...), msleep(...)

    if(m_pVideoPlayVector[m_curComboxIndex]){
        qDebug() << "delete play";
        m_pVideoPlayVector[m_curComboxIndex]->Deinit();
        // delete m_pVideoPlayVector[m_curComboxIndex];
//        m_pVideoPlayVector[m_curComboxIndex] = nullptr;
    }

    if(m_pVideoThreadVector[m_curComboxIndex]->isFinished()){
        qDebug() << "delete thread";
        m_pVideoThreadVector[m_curComboxIndex]->exit();
       // delete  m_pVideoThreadVector[m_curComboxIndex];
       // m_pVideoThreadVector[m_curComboxIndex] = nullptr;
    }

    //ui->pushButton_Start->setEnabled(true);
   // ui->pushButton_Stop->setEnabled(false);
}

void Widget::SetImage1(const QImage &image)
{
    int tempWidth = m_pLabelVector[m_curComboxIndex]->geometry().width();
    int tempHeight = m_pLabelVector[m_curComboxIndex]->geometry().height();
    if (image.height() > 0) {
        QPixmap pix = QPixmap::fromImage(image.scaled(tempWidth, tempHeight));
        m_pLabelVector[m_curComboxIndex]->setPixmap(pix);
    }
}

void Widget::on_comboBox_activated(int index)
{
    m_curComboxIndex = index;
    qDebug() << "change channel index: " << m_curComboxIndex;
    if(m_VideoChannelStatus[m_curComboxIndex] == 2) {

        qDebug() << "channel status : start" ;
        ui->pushButton_Start->setEnabled(false);
        ui->pushButton_Stop->setEnabled(true);
    }else {
         qDebug() << "channel status : stop" ;
        ui->pushButton_Start->setEnabled(true);
        ui->pushButton_Stop->setEnabled(false);
    }
}
