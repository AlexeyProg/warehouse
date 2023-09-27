#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "warehousedialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    WarehouseDialog *wareDial;

public slots:
    void redirect_to_warehouse();
};
#endif // MAINWINDOW_H
