#include "frmcomtool.h"
#include <QApplication>
#include "myhelper.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/main.ico"));
    myHelper::setUTF8Code();

    QSplashScreen *splash=new QSplashScreen;
    QPixmap pix(":/main.ico");

    splash->setPixmap(pix);
    splash->show();
    a.processEvents();//这样可以保证程序一直可以响应鼠标键盘上事件
    splash->showMessage("正在载入，请稍等……");

    QDateTime n=QDateTime::currentDateTime();
    QDateTime now;
    do{
        now=QDateTime::currentDateTime();
    } while (n.secsTo(now)<=2);//3为需要延时的秒数

    frmComTool w;
    w.show();

    return a.exec();
}
