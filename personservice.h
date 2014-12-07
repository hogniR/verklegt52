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
    void connect(string name, string computer);
};
#endif // PERSONSERVICE_H
