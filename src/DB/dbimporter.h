#ifndef DBIMPORTER_H
#define DBIMPORTER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class DBImporter : public QObject
{
public:
    explicit DBImporter(QObject *parent = nullptr);
    void connection();

    QSqlDatabase db;

signals:

};

#endif // DBIMPORTER_H
