#include "frmcomtool.h"
#include <QApplication>
#include "myhelper.h"
#include <QSplashScreen>


void printscreeninfo()
{
   QDesktopWidget *dwsktopwidget = QApplication::desktop();
   //获取可用桌面大小
   QRect deskrect = dwsktopwidget->availableGeometry();
   //获取设备屏幕大小
   QRect screenrect = dwsktopwidget->screenGeometry();

   //获取系统设置的屏幕个数（屏幕拷贝方式该值为1）
   int scrcount = dwsktopwidget->screenCount();

   qCritical("deskrect.w==%s\n",qPrintable(QString::number(deskrect.width())));
   qCritical("deskrect.h==%s\n",qPrintable(QString::number(deskrect.height())));

   qCritical("screenrect.w==%s\n",qPrintable(QString::number(screenrect.width())));
   qCritical("screenrect.h==%s\n",qPrintable(QString::number(screenrect.height())));

   qCritical("scrcount==%s\n",qPrintable(QString::number(scrcount)));
   //获取整个桌面大小，扩展和主界面的总和
   qCritical("desktop.w==%s\n",qPrintable(QString::number(QApplication::desktop()->width())));

   qCritical("desktop.h==%s\n",qPrintable(QString::number(QApplication::desktop()->height())));
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/main.ico"));
    myHelper::setUTF8Code();

    QPixmap pixmap(":/start.png");
    QSplashScreen splash(pixmap);
    splash.show();
    splash.showMessage("正在载入，请稍等……",Qt::AlignLeft|Qt::AlignTop,Qt::darkBlue);
    QThread::msleep(500);
//    a.processEvents();//这样可以保证程序一直可以响应鼠标键盘上事件
    splash.showMessage("建立连接，请稍等……",Qt::AlignLeft|Qt::AlignTop,Qt::darkBlue);
    QThread::msleep(500);
//    QDateTime n=QDateTime::currentDateTime();
//    QDateTime now;
//    do{
//        now=QDateTime::currentDateTime();
//        a.processEvents();//这样可以保证程序一直可以响应鼠标键盘上事件
//    } while (n.secsTo(now)<=10);//3为需要延时的秒数
//    a.processEvents();//这样可以保证程序一直可以响应鼠标键盘上事件
    printscreeninfo();

    frmComTool w;
    w.show();
    splash.finish(&w);

    return a.exec();
}
