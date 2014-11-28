#ifndef MANAGER_H
#define MANAGER_H

#include "person.h"
#include <list>

class Manager
{
public:
    Manager();
    void add(Person p);

private:
    list<Person> mylist;
};

#endif // MANAGER_H
