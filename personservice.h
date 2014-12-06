#ifndef PERSONSERVICE_H
#define PERSONSERVICE_H
#include "person.h"
#include "personrepo.h"

class personService
{
private:
    personRepo personRepository;
public:
    personService();
    void add(Person p);
    void add_computer(Computer c);
    void printList();
    void search(string name);
    void sortName();
};
#endif // PERSONSERVICE_H
