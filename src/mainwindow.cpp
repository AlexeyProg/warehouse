#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createUI();
    connect(instruments_but, SIGNAL(clicked()), this, SLOT(changeToInstruments()));
    connect(materials_but, SIGNAL(clicked()), this, SLOT(changeToMaterials()));



    /*
     * i need to create stack vertical layout vecause it will be labels in top of it
     * and many items like products below it ;
     */


    mainlay = new QHBoxLayout(this);
    mainlay->addLayout(but_lay);
    mainlay->addWidget(stack_widg);

    centralWidget()->setLayout(mainlay);


//    QVBoxLayout *stack_lay = new QVBoxLayout();
//    stack_lay->addWidget(stack_widg);
//    mainlay->addLayout(stack_lay);


//    QString n  = "Drel'";
//    QString i = ":/image-files/img/drel1.jpg";
//    QString price1 = "100$";
//    Item *test = new Item(n,i,3,price1,this);
//    instruments_list.push_back(test);

//    QString n2 = "Perforator";
//    QString i2 = ":/image-files/img/perfo.png";
//    QString price2 = "200$";
//    Item *test1 = new Item(n2,i2,5,price2,this);
//    instruments_list.push_back(test1);

//    QString n3 = "Montaj";
//    QString i3 = ":/image-files/img/montaj_pistol.jpg";
//    QString price3 = "300$";
//    Item *test2 = new Item(n3,i3,7,price3,this);
//    instruments_list.push_back(test2);

//    show_content();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeToInstruments()
{
    stack_widg->setCurrentIndex(0);
}

void MainWindow::changeToMaterials()
{
    stack_widg->setCurrentIndex(1);
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
//        ui->gridLayout->addWidget(it,row,col);
        col++;
    }
}

void MainWindow::createUI()
{
    this->setWindowTitle("Warehouse");
    stack_widg = new QStackedWidget(this);
    instruments_but = new QPushButton(this);
    instruments_but->setText("Instum");
    materials_but = new QPushButton(this);
    materials_but->setText("Materials");

    categoryInstr = new QWidget(this);
    QLabel *inst_label = new QLabel("Instruments", categoryInstr);
    inst_label->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    categoryMaterials = new QWidget(this);
    QLabel *mater_label = new QLabel("Materials", categoryMaterials);
    mater_label->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    stack_widg->addWidget(categoryInstr);
    stack_widg->addWidget(categoryMaterials);
    but_lay = new QVBoxLayout();
    but_lay->addWidget(instruments_but);
    but_lay->addWidget(materials_but);


    stack_vhbox_instr = new QVBoxLayout(categoryInstr);
    stack_vhbox_instr->addWidget(inst_label);

    stack_vhbox_mater = new QVBoxLayout(categoryMaterials);
    stack_vhbox_mater->addWidget(mater_label);

//    stack_vhbox->addWidget(inst_label);
//    QGridLayout *grid_lay = new QGridLayout(categoryInstr);

}
