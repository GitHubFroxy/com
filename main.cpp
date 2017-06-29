#include "frmcomtool.h"
#include <QApplication>
#include "myhelper.h"
#include <QSplashScreen>

#if 1
#include <QDateTime>
#include <QFile>
#include <QTextStream>
QString  logfile;
void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    // 加锁

    static QMutex mutex;
    mutex.lock();

    QByteArray localMsg = msg.toLocal8Bit();

    QString strMsg("");
    switch(type)
    {
    case QtDebugMsg:
        strMsg = QString("Debug:");
        break;
    case QtWarningMsg:
        strMsg = QString("Warning:");
        break;
    case QtCriticalMsg:
        strMsg = QString("Critical:");
        break;
    case QtFatalMsg:
        strMsg = QString("Fatal:");
        break;
    }

    // 设置输出信息格式
    QString strDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
    QString strMessage = QString("Message:%1 File:%2  Line:%3  Function:%4  DateTime:%5")
            .arg(localMsg.constData()).arg(context.file).arg(context.line).arg(context.function).arg(strDateTime);

    // 输出信息至文件中（读写、追加形式）

    QFile file(logfile);
    file.open(QIODevice::ReadWrite | QIODevice::Append);
    QTextStream stream(&file);
    stream << strMessage << "\r\n";
    file.flush();
    file.close();

    // 解锁
    mutex.unlock();
}
#endif
#if 0
// 自定义消息处理程序
void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    switch (type) {
    case QtDebugMsg:
        fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtInfoMsg:
        fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtWarningMsg:
        fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtCriticalMsg:
        fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        abort();
    }
}
#endif

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

    QDateTime now = QDateTime::currentDateTime();
    QString name = now.toString("yyyy-MM-dd-HH-mm-ss");
    name.append(" log");
    logfile = QString("%1/%2.txt").arg(AppPath).arg(name);

    // 安装消息处理程序
    qInstallMessageHandler(myMessageOutput);

    a.setWindowIcon(QIcon(":/main.ico"));
    myHelper::setUTF8Code();

    qDebug("This is a debug message.");
    qWarning("This is a warning message.");
    qCritical("This is a critical message.");

    QPixmap pixmap(":/start.png");
    QSplashScreen splash(pixmap);
    splash.show();
    splash.showMessage("正在载入，请稍等……",Qt::AlignLeft|Qt::AlignTop,Qt::darkBlue);
    QThread::msleep(500);
//    a.processEvents();//这样可以保证程序一直可以响应鼠标键盘上事件
    splash.showMessage("建立连接，请稍等……",Qt::AlignLeft|Qt::AlignTop,Qt::darkBlue);
    QThread::msleep(500);

    printscreeninfo();

    frmComTool w;
    w.show();
    splash.finish(&w);

    return a.exec();
}
