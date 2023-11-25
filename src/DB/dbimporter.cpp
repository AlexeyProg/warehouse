#include "dbimporter.h"

DBImporter::DBImporter(QObject *parent)
    : QObject{parent}
{
    connection();
}

void DBImporter::connection()
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName("ware instr");
    db.setHostName("localhost");
    bool ok = db.open();
    if(!ok)
    {
        qDebug() << "Incorrect connection";
        QSqlError err = db.lastError();
        qDebug() << err.text();
    }
    else
        qDebug() << "Correct connection";
}
