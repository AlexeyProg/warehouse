#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "item.h"
#include <QStackedWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void changeToInstruments();
    void changeToMaterials();

private:
    Ui::MainWindow *ui;
    QPushButton *instruments_but;
    QPushButton *materials_but;

    QStackedWidget *stack_widg;
    void show_content();
    void createUI();
    QWidget *categoryInstr;
    QWidget *categoryMaterials;
    QHBoxLayout *mainlay;
    QVBoxLayout *but_lay;
    QVBoxLayout *stack_vhbox_instr;
    QVBoxLayout *stack_vhbox_mater;

    QList<Item*>instruments_list;
    QList<Item*> materials_list;

};
#endif // MAINWINDOW_H
