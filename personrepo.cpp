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
    QString queryExec = "SELECT p.*, c.Name FROM Computer c INNER JOIN Connector o ON o.c_ID = c.ID INNER JOIN Person p ON o.p_ID = p.ID";
    switch(option)
    {
        case 1:
            queryExec = queryExec + " ORDER BY Name";
            break;
        case 2:
            queryExec = queryExec + " ORDER BY Gender";
            break;
        case 3:
            queryExec = queryExec + " ORDER BY birthYear";
            break;
        case 4:
            queryExec = queryExec + " ORDER BY deathYear";
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

bool personRepo::connect(string name, string computer)
{
    bool found = false;

    if(db.open())
    {
        QSqlQuery query;
        query.exec("SELECT * FROM Person WHERE Name LIKE '%" + QString(name.c_str()) + "%'");

        if(query.next())
        {
            QString id_p = query.value("ID").toString();
            found = true;

            query.exec("SELECT * FROM Computer WHERE Name LIKE '%" + QString(computer.c_str()) + "%'");

            if(query.next())
            {
                QString id_c = query.value("ID").toString();
                query.exec("INSERT INTO Connector(p_ID, c_ID) VALUES("+ id_p +", "+ id_c +")");
            }
            else
                found = false;
        }
        else
            found = false;
    }
    db.close();
    return found;
}

