#include "computerrepo.h"

computerRepo::computerRepo()
{
<<<<<<< HEAD
    db = getDatabaseConnection();
}

QSqlDatabase computerRepo::getDatabaseConnection()
{
    QSqlDatabase db;

    if(QSqlDatabase::contains())
    {
        db = QSqlDatabase::database();
    }
    else
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("DB.sqlite");

        db.open();
    }
    return db;
=======
    //db = QSqlDatabase::addDatabase("QSQLITE");
    //QString dbName = "DB.sqlite";
    //db.setDatabaseName(dbName);
>>>>>>> 5ee430367865cdd209183dfff3e923d5b8e0bd03
}

void computerRepo::add(Computer c)
{
    if(db.open())
    {
        QSqlQuery query;
        query.exec("INSERT INTO Computer('Name','Year','Type','Made')"
                   "VALUES('"+QString((c.name).c_str())+"',"
                   " "+QString::number(c.year)+", '"+QString((c.type).c_str())+"',"
                   " "+QString::number(c.made)+")");
    }
    db.close();
}

QSqlQuery computerRepo::printList(int option)
{
    QString queryExec;
    switch(option)
    {
        case 1:
            queryExec = "SELECT * FROM Computer ORDER BY Name";
            break;
        case 2:
            queryExec = "SELECT * FROM Computer ORDER BY Year";
            break;
        case 3:
            queryExec = "SELECT * FROM Computer ORDER BY Type";
            break;
        case 4:
            queryExec = "SELECT * FROM Computer ORDER BY Made";
            break;
    }

    if(db.open())
    {
        QSqlQuery query;
        query.exec(queryExec);

        if(query.next())
        {
            query.previous();
            return query;
        }
    }
    db.close();
    return QSqlQuery();
}

QSqlQuery computerRepo::search(string name)
{
    if(db.open())
    {
        QSqlQuery query;
        query.exec("SELECT * FROM Computer WHERE Name LIKE '%" + QString(name.c_str()) + "%'");
        if(query.next())
        {
            query.previous();
            return query;
        }
    }
    db.close();
    return QSqlQuery();
}
