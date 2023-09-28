#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Warehouse");

    QString n  = "drel";
    QString i = ":/image-files/img/drel1.jpg";
    Item *test = new Item(n,i,this);
    instruments_list.push_back(test);

    Item *test1 = new Item(n,i,this);
    instruments_list.push_back(test1);

    Item *test2 = new Item(n,i,this);
    instruments_list.push_back(test2);

    Item *test3 = new Item(n,i,this);
    instruments_list.push_back(test3);

    Item *test4 = new Item(n,i,this);
    instruments_list.push_back(test4);

    Item *test5 = new Item(n,i,this);
    instruments_list.push_back(test5);
    show_content();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::show_content()
{
    int row = 0;
    int col = 0;
    for(const auto &it : instruments_list)
    {
        if(col == 3)
        {
            col = 0;
            row++;
        }
        ui->gridLayout->addWidget(it,row,col);
        col++;
    }
}
