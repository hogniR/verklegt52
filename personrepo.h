#ifndef PERSONREPO_H
#define PERSONREPO_H

#include <list>
#include <fstream>
#include "person.h"

using namespace std;

class personRepo
{
private:
    list<Person> personList;
public:
    personRepo();
    ~personRepo();
    void add(Person p);
    void printList();
    void sortName();
};

#endif // PERSONREPO_H
