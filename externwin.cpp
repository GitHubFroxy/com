#include "externwin.h"
#include "ui_externwin.h"

ExternWin::ExternWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExternWin)
{
    ui->setupUi(this);
}

ExternWin::~ExternWin()
{
    delete ui;
}
