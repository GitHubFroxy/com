#ifndef FRMCOMTOOL_H
#define FRMCOMTOOL_H

#include <QWidget>

class QextSerialPort;
class QTcpSocket;

class ExternWin;

QT_BEGIN_NAMESPACE
class QCheckBox;
class QDialogButtonBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QPushButton;
QT_END_NAMESPACE

namespace Ui
{
class frmComTool;
}

class frmComTool : public QWidget
{
	Q_OBJECT

public:
	explicit frmComTool(QWidget *parent = 0);
	~frmComTool();

private:
	Ui::frmComTool *ui;

    bool comOk;                 //串口是否打开
    QextSerialPort *com;        //串口通信对象
	QTimer *timerRead;          //定时读取串口数据
	QTimer *timerSend;          //定时发送串口数据
	QTimer *timerSave;          //定时保存串口数据

	int maxCount;               //最大显示行数
	int currentCount;           //当前显示行数
	int sleepTime;              //接收延时时间
	int sendCount;              //发送数据计数
	int receiveCount;           //接收数据计数
	bool isShow;                //是否显示数据

	QStringList keys;           //模拟设备回复数据key
	QStringList values;         //模拟设备回复数据value

    bool tcpOk;                 //网络是否正常
    QTcpSocket *socket;         //网络连接对象
    QTimer *timerConnect;       //定时器重连

    QCheckBox *wholeWordsCheckBox;
    QWidget *extension;

    ExternWin *externwin;//扩展窗口

private slots:
	void initForm();                //初始化窗体数据
    void initConfig();              //初始化配置文件
    void saveConfig();              //保存配置文件
	void readData();                //读取串口数据
	void sendData();                //发送串口数据
    void sendData_1();
    void sendData_2();
    void sendData_3();
	void sendData(QString data);    //发送串口数据带参数
	void saveData();                //保存串口数据

	void readSendData();            //读取发送配置文件数据
	void readDeviceData();          //读取设备转发文件数据

	void changeEnable(bool b);      //改变状态
	void append(quint8 type, QString msg);

    void on_ck_OpenWin(void);//打开扩展窗口

private slots:
    void connectNet();
    void readDataNet();
    void readErrorNet();

private slots:
	void on_btnOpen_clicked();
	void on_btnStopShow_clicked();
	void on_btnSendCount_clicked();
	void on_btnReceiveCount_clicked();
    void on_btnClear_clicked();
	void on_btnData_clicked();

	void on_ckAutoSend_stateChanged(int arg1);
    void on_ckAutoSave_stateChanged(int arg1);

    void on_btnStart_clicked();
    void on_ckTop_toggled(bool checked);
};

#endif // FRMCOMTOOL_H
