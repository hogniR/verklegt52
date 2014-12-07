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

    void add(Person p);
    bool connect(string name, string computer);
    QSqlQuery printList(int option);
    QSqlQuery search(string name);
};

#endif // PERSONREPO_H
