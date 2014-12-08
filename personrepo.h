#ifndef PERSONREPO_H
#define PERSONREPO_H

#include <functional>
#include <cstdlib>
#include <Qtsql>

#include "person.h"

using namespace std;

class personRepo
{
private:
    QSqlDatabase db;
public:
    personRepo();
    QSqlDatabase getDatabaseConnection();

    void add(Person p);
    QSqlQuery printList(int option);
    QSqlQuery search(string name);
};

#endif // PERSONREPO_H
