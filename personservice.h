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
    void Delete(string name);
    void search(string name);
    void sortName();
    void sortGender();
    void sortDyear();
    void sortByear();
};
#endif // PERSONSERVICE_H
