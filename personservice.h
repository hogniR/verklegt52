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
    void printList();
    void sortName();
    void sortGender();
    void sortDyear();
    void sortByear();
};
#endif // PERSONSERVICE_H
