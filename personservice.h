#ifndef PERSONSERVICE_H
#define PERSONSERVICE_H

#include "person.h"
#include "personrepo.h"

class personService
{
private:
    personRepo personRepository;
public:
    void add(Person p);
    bool connect(string name, string computer);
    QSqlQuery printList(int option);
    QSqlQuery search(string name);
    QSqlQuery searchforadd(string name);
};
#endif // PERSONSERVICE_H
