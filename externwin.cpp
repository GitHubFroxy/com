#include "externwin.h"
#include "ui_externwin.h"

ExternWin::ExternWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExternWin)
{
    ui->setupUi(this);
    this->initForm();
    this->initConfig();
}
void ExternWin::initForm()
{
    ui->address->setInputMask("000.000.000.000;_");
    ui->netmask->setInputMask("000.000.000.000;_");
    ui->network->setInputMask("000.000.000.000;_");
    ui->gateway->setInputMask("000.000.000.000;_");

    connect(ui->write,SIGNAL(pressed()),this,SLOT(write()));
    connect(ui->load,SIGNAL(pressed()),this,SLOT(load()));
}
void ExternWin::initConfig()
{
    this->load();
}
void ExternWin::write(){
    QString strAll;
    QStringList strList;
    QFile readFile("test.txt");
    if(readFile.open((QIODevice::ReadOnly|QIODevice::Text)))
    {
        QTextStream stream(&readFile);
        strAll=stream.readAll();
    }
    readFile.close();
    QFile writeFile("test.txt");
    if(writeFile.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        QTextStream stream(&writeFile);
        strList=strAll.split("\n");
        for(int i=0;i<strList.count();i++)
        {
            if(i==strList.count()-1)
            {
                //最后一行不需要换行
                stream<<strList.at(i);
            }
            else
            {
                stream<<strList.at(i)<<'\n';
            }

            if(strList.at(i).contains("iface eth0 inet static"))
            {
                QString tempStr=strList.at(i+1);
                tempStr.replace(0,tempStr.length(),"                                      ");
                tempStr = "        address ";
                tempStr.append(ui->address->text());
                stream<<tempStr<<'\n';

                tempStr=strList.at(i+2);
                tempStr.replace(0,tempStr.length(),"                                      ");
                tempStr = "        netmask ";
                tempStr.append(ui->netmask->text());
                stream<<tempStr<<'\n';

                tempStr=strList.at(i+3);
                tempStr.replace(0,tempStr.length(),"                                      ");
                tempStr = "        network ";
                tempStr.append(ui->network->text());
                stream<<tempStr<<'\n';


                tempStr=strList.at(i+4);
                tempStr.replace(0,tempStr.length(),"                                      ");
                tempStr = "        gateway ";
                tempStr.append(ui->gateway->text());
                stream<<tempStr<<'\n';

                i+=4;
            }
        }
    }
    writeFile.close();
//两外一种配置文件方法
#if 0
    QString path="text.txt";
    QSettings settings(path,QSettings::IniFormat);
    QString value=settings.value("host","127.0.0.1").toString();

    settings.setValue("host","192.168.1.110");
#endif

}
void ExternWin::load(){
    QString strAll;
    QStringList strList;
    QFile readFile("test.txt");
    if(readFile.open((QIODevice::ReadOnly|QIODevice::Text)))
    {
        QTextStream stream(&readFile);
        strAll=stream.readAll();

        strList=strAll.split("\n");
        for(int i=0;i<strList.count();i++)
        {
            if(i==strList.count()-1)
            {
                //最后一行不需要换行
                stream<<strList.at(i);
            }
            else
            {
                stream<<strList.at(i)<<'\n';
            }

            if(strList.at(i).contains("iface eth0 inet static"))
            {
                QString tempStr=strList.at(i+1);
                tempStr = tempStr.section(' ', 3, -1);
                ui->address->setText(tempStr);

                tempStr=strList.at(i+2);
                tempStr = tempStr.section(' ', 3, -1);
                ui->netmask->setText(tempStr);

                tempStr=strList.at(i+3);
                tempStr = tempStr.section(' ', 3, -1);
                ui->network->setText(tempStr);


                tempStr=strList.at(i+4);
                tempStr = tempStr.section(' ', 3, -1);
                ui->gateway->setText(tempStr);

                i+=4;
            }
        }
    }
    readFile.close();
}
ExternWin::~ExternWin()
{
    delete ui;
}
