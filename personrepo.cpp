#include "personrepo.h"

personRepo::personRepo(){

    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "DB.sqlite";
    db.setDatabaseName(dbName);
}

void personRepo::add(Person p){
    if(db.open())
    {
        QSqlQuery query;
        query.exec("INSERT INTO Person('Name','Gender','birthYear','deathYear')"
                   "VALUES('"+QString((p.name).c_str())+"',"
                   "'" +QString((p.gender).c_str())+"', "+QString::number(p.birthYear)+","
                   " "+QString::number(p.deathYear)+")");

        db.close();
    }
}

void personRepo::add_computer(Computer c){
    if(db.open())
    {
        QSqlQuery query;
        query.exec("INSERT INTO Computer('Name','Year','Type','Made')"
                   "VALUES('"+QString((c.name).c_str())+"',"
                   " "+QString::number(c.year)+", '"+QString((c.type).c_str())+"',"
                   " "+QString::number(c.made)+")");

        db.close();
    }
}

void personRepo::printList(int option)
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

        while(query.next())
        {
            cout << "Name:          " << query.value("Name").toString().toStdString() << endl;
            cout << "Gender:        " << query.value("Gender").toString().toStdString() << endl;
            cout << "Birth year:    " << query.value("birthYear").toString().toStdString() << endl;
            cout << "Year of death: " << query.value("deathYear").toString().toStdString() << endl;
            cout << endl;
        }
    }
    db.close();
}

void personRepo::search(string name)
{
    if(db.open())
    {
        QSqlQuery query;
        query.exec("SELECT * FROM Person WHERE Name = '" + QString(name.c_str()) + "'");
        if(query.next() != false)
        {
            query.previous();
            while(query.next())
            {
                cout << endl;
                cout << "Name:          " << query.value("Name").toString().toStdString() << endl;
                cout << "Gender:        " << query.value("Gender").toString().toStdString() << endl;
                cout << "Birth year:    " << query.value("birthYear").toString().toStdString() << endl;
                cout << "Year of death: " << query.value("deathYear").toString().toStdString() << endl;
                cout << endl;
            }
        }
        else
        {
            cout << "No matches found" << endl;
        }
    }
    db.close();
}

void personRepo::connect(string name, string computer)
{
    if(db.open())
    {
        QSqlQuery query;
        query.exec("SELECT ID FROM Person WHERE Name = '" + QString(name.c_str()) + "'");
        if(query.next() != false)
        {
            QString id = query.value("ID").toString();

            cout << id.toStdString() << endl;
        }
    }
    else
    {
        cout << "Could not connect." << endl;
    }
}

