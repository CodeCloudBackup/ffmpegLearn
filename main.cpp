#include "widget.h"

#include <QApplication>
#include "mdump.h"
MiniDumper dump;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.window()->setWindowTitle("安防监控软件V1.0");
    w.show();
    return a.exec();
}
