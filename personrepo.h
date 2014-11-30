#ifndef PERSONREPO_H
#define PERSONREPO_H

#include <list>
#include <functional>
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
    void Delete(string name);
};

#endif // PERSONREPO_H
