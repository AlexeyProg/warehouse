#include "item.h"
#include <QPushButton>
#include <QPixmap>
#include <QIcon>
#include <QLabel>
#include <QDebug>
#include <QLineEdit>
#include <QVBoxLayout>


Item::Item(QString &mName, QString &mImage, int mQuaintity, QString &mPrice, QWidget *parent)
    : QWidget{parent}, name(mName), image(mImage), quantity(mQuaintity), price(mPrice)
{
    generate_widget();
}

void Item::setImage(QString &resource)
{
    this->image = resource;
}

void Item::generate_widget()
{
    int wid_w = 180;
    int wid_h = 240;
    this->setGeometry(0,0,wid_w,wid_h);
    QLabel *lab_pix = new QLabel(this);
    QPixmap mp(image);
    QPixmap res_p = mp.scaled(wid_w,wid_h - 80);//160
    lab_pix->setPixmap(res_p);

    QLabel *name_l = new QLabel(this);
    name_l->setText(this->name);
    name_l->setGeometry(0, res_p.height() + 5, wid_w, 20);
    name_l->setAlignment(Qt::AlignCenter);
    name_l->setStyleSheet("font-size: 14px; color: blue;");
    //+ "\nQuantity: " + QString::number(this->quantity) + "\nPrice: " + price

    QLabel *quan_l = new QLabel(this);
    quan_l->setText("Quantity: ");
    quan_l->setGeometry(0,res_p.height() + 30, wid_w/2, wid_h - res_p.width() - 40);
    quan_l->setStyleSheet("font-size: 14px; color: blue;");

    QLineEdit *quan_ed = new QLineEdit(this);
    quan_ed->setText(QString::number(this->quantity));
    quan_ed->setAlignment(Qt::AlignCenter);
    quan_ed->setGeometry(quan_l->width(), res_p.height() + 30, wid_w/2, wid_h - res_p.width() - 40);

    QLabel *price_l = new QLabel(this);
    price_l->setText("Price: ");
    price_l->setGeometry(0,res_p.height() + 50, wid_w/2, wid_h - res_p.width() - 40);
    price_l->setStyleSheet("font-size: 14px; color: blue;");

    QLineEdit *price_ed = new QLineEdit(this);
    price_ed->setText(this->price);
    price_ed->setAlignment(Qt::AlignCenter);
    price_ed->setGeometry(quan_l->width(), res_p.height() + 50, wid_w/2, wid_h - res_p.width() - 40);

}
