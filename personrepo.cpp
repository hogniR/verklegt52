#include "personrepo.h"

personRepo::personRepo()
{
    db = getDatabaseConnection();
}

QSqlDatabase personRepo::getDatabaseConnection()
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
}

void personRepo::add(Person p)
{
    if(db.open())
    {
        QSqlQuery query;
        query.exec("INSERT INTO Person('Name','Gender','birthYear','deathYear')"
                   "VALUES('"+QString((p.name).c_str())+"',"
                   "'" +QString((p.gender).c_str())+"', "+QString::number(p.birthYear)+","
                   " "+QString::number(p.deathYear)+")");
    }
    db.close();
}

QSqlQuery personRepo::printList(int option)
{
    QString queryExec;
    switch(option)
    {
        case 1:
            queryExec = "SELECT * FROM Person ORDER BY Name";
            break;
        case 2:
            queryExec = "SELECT * FROM Person ORDER BY Gender";
            break;
        case 3:
            queryExec = "SELECT * FROM Person ORDER BY birthYear";
            break;
        case 4:
            queryExec = "SELECT * FROM Person ORDER BY deathYear";
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

QSqlQuery personRepo::search(string name)
{
    if(db.open())
    {
        QSqlQuery query;
        query.exec("SELECT * FROM Person WHERE Name LIKE '%" + QString(name.c_str()) + "%'");
        if(query.next())
        {
            query.previous();
            return query;
        }
    }
    db.close();
    return QSqlQuery();
}

