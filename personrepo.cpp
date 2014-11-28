#include "personrepo.h"

personRepo::personRepo()
{
    personList = list<Person>();
}

void personRepo::add(Person p) {
    personList.push_back(p);
}
