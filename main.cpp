#include "frmcomtool.h"
#include <QApplication>
#include "myhelper.h"
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/main.ico"));
    myHelper::setUTF8Code();

    QPixmap pixmap(":/start.png");
    QSplashScreen splash(pixmap);
    splash.show();
    splash.showMessage("正在载入，请稍等……",Qt::AlignRight|Qt::AlignBottom,Qt::darkBlue);
    QThread::msleep(1000);
//    a.processEvents();//这样可以保证程序一直可以响应鼠标键盘上事件
    splash.showMessage("建立连接，请稍等……",Qt::AlignRight|Qt::AlignBottom,Qt::darkBlue);
    QThread::msleep(500);
//    QDateTime n=QDateTime::currentDateTime();
//    QDateTime now;
//    do{
//        now=QDateTime::currentDateTime();
//        a.processEvents();//这样可以保证程序一直可以响应鼠标键盘上事件
//    } while (n.secsTo(now)<=10);//3为需要延时的秒数
//    a.processEvents();//这样可以保证程序一直可以响应鼠标键盘上事件

    frmComTool w;
    w.show();

    return a.exec();
}
