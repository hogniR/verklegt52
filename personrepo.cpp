#include "personrepo.h"

personRepo::personRepo(){

    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "DB.sqlite";
    db.setDatabaseName(dbName);
}

personRepo::~personRepo(){

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

void personRepo::printList(){

    if(db.open())
    {
        QSqlQuery query;
        query.exec("SELECT * FROM Computer");

        while(query.next()){

        cout << query.value("Name").toString().toStdString() << " ";
        //cout << query.value("Year").toString().toStdString() << " ";
        cout << query.value("Type").toString().toStdString() << endl;
        }
    }
    db.close();
}

void personRepo::search(string name) {

    bool found = false;
    for(std::list<Person>::iterator it = personList.begin(); it != personList.end(); it++)
    {
        if((*it).name == name)
        {
            found = true;
            cout << *it << endl;
            break;
        }
    }

    if(found == false)
        cout << "The name was not found." << endl;
}

void personRepo::sortName()
{
    //personList.sort(compareName);
}
