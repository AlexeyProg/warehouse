#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Warehouse");

    QString n  = "Drel'";
    QString i = ":/image-files/img/drel1.jpg";
    QString price1 = "100$";
    Item *test = new Item(n,i,3,price1,this);
    instruments_list.push_back(test);

    QString n2 = "Perforator";
    QString i2 = ":/image-files/img/perfo.png";
    QString price2 = "200$";
    Item *test1 = new Item(n2,i2,5,price2,this);
    instruments_list.push_back(test1);

    QString n3 = "Montaj";
    QString i3 = ":/image-files/img/montaj_pistol.jpg";
    QString price3 = "300$";
    Item *test2 = new Item(n3,i3,7,price3,this);
    instruments_list.push_back(test2);

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
