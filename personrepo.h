#ifndef PERSONREPO_H
#define PERSONREPO_H

#include <list>
#include "person.h"

using namespace std;

class personRepo
{
private:
    list<Person> personList;
public:
    personRepo();
    void add(Person p);
};

#endif // PERSONREPO_H
