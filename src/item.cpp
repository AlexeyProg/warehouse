#include "item.h"
#include <QPushButton>
#include <QPixmap>
#include <QIcon>
#include <QLabel>
#include <QDebug>

static int items_counter = 1;

Item::Item(QString &mName, QString &mImage, QWidget *parent)
    : QWidget{parent}, name(mName), image(mImage)
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
    int wid_h = 200;
    this->setGeometry(0,0,wid_w,wid_h);
    QLabel *lab_pix = new QLabel(this);
    QPixmap mp(image);
    QPixmap res_p = mp.scaled(wid_w,wid_h - 20);
    lab_pix->setPixmap(res_p);

    QLabel *name_l = new QLabel(this);
    name_l->setText(this->name);
    name_l->setGeometry(0,wid_h + 5,wid_w,20);
    name_l->setAlignment(Qt::AlignCenter);
    name_l->setStyleSheet("font-size: 16px; color: blue; background-color: yellow;");
    qDebug() << name.size() << name_l->size();
}
