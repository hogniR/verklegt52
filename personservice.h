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
};
#endif // PERSONSERVICE_H
