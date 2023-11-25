#ifndef MENUDIALOG_H
#define MENUDIALOG_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class MenuDialog;
}

class MenuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MenuDialog(QWidget *parent = nullptr);
    ~MenuDialog();


private:
    Ui::MenuDialog *ui;
    MainWindow win;
public slots:
    void redirect_to_warehouse();
    void quit();
};

#endif // MENUDIALOG_H
