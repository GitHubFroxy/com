#ifndef EXTERNWIN_H
#define EXTERNWIN_H

#include <QWidget>

namespace Ui {
class ExternWin;
}

class ExternWin : public QWidget
{
    Q_OBJECT

public:
    explicit ExternWin(QWidget *parent = 0);
    ~ExternWin();

private:
    Ui::ExternWin *ui;
};

#endif // EXTERNWIN_H
