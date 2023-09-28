#ifndef ITEM_H
#define ITEM_H

#include <QWidget>
#include <QLabel>


class Item : public QWidget
{
    Q_OBJECT
public:
    explicit Item(QString &mName, QString &mImage, QWidget *parent = nullptr);
    void setImage(QString &resource);


signals:

private:
    void generate_widget();
    QString name;
    QString image;

};

#endif // ITEM_H
