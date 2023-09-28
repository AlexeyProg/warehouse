#include "menudialog.h"
#include "ui_menudialog.h"

MenuDialog::MenuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuDialog)
{
    ui->setupUi(this);
    ui->verticalLayout->setAlignment(Qt::AlignCenter);

    connect(ui->pushButton_warehouse, SIGNAL(clicked()), this, SLOT(redirect_to_warehouse()));
}

MenuDialog::~MenuDialog()
{
    delete ui;
}

void MenuDialog::redirect_to_warehouse()
{
    this->close();
    win.show();
}
