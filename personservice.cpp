#include "personservice.h"

void personService::add(Person p)
{
    personRepository.add(p);
}

QSqlQuery personService::printList(int option)
{
    return personRepository.printList(option);
}

QSqlQuery personService::search(string name)
{
    return personRepository.search(name);
}
