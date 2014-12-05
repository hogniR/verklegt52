#include "personrepo.h"

personRepo::personRepo(){
/*
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "DB.sqlite";
    db.setDatabaseName(dbName); */
}

personRepo::~personRepo(){

}

void personRepo::add(Person p)
{
    /*
    if(db.open())
    {
        string make, model, color;

        cout << "Make: ";
        cin >> make;
        cout << "Model: ";
        cin >> model;
        cout << "Color: ";
        cin >> color;

        QSqlQuery query;
        query.exec("INSERT INTO Car('Make','Model','Color','Doors') VALUES ('" + QString(make.c_str()) + "','" +QString(model.c_str()) + "', '" + QString(color.c_str()) + "', 5)");

        db.close();
        */
}

void personRepo::printList(){
   /* QSqlQuery query;
        query.exec("SELECT * FROM Car");

        while(query.next()){

        cout << query.value("Make").toString().toStdString() << " ";
        cout << query.value("Model").toString().toStdString() << " ";
        cout << query.value("Color").toString().toStdString() << endl;
        }
    */
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
