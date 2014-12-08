#include "computerrepo.h"

computerRepo::computerRepo()
{

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
    QString queryExec = "SELECT c.*, p.Name FROM Computer c INNER JOIN Connector o ON o.c_ID = c.ID INNER JOIN Person p ON o.p_ID = p.ID";
    switch(option)
    {
        case 1:
            queryExec = queryExec + " ORDER BY Name";
            break;
        case 2:
            queryExec = queryExec + " ORDER BY Year";
            break;
        case 3:
            queryExec = queryExec + " ORDER BY Type";
            break;
        case 4:
            queryExec = queryExec + " ORDER BY Made";
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
