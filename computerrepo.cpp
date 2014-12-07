#include "computerrepo.h"

computerRepo::computerRepo()
{
    //db = QSqlDatabase::addDatabase("QSQLITE");
    //QString dbName = "DB.sqlite";
    //db.setDatabaseName(dbName);
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