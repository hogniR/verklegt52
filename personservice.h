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
    void printList(int option);
    void search(string name);
};
#endif // PERSONSERVICE_H
