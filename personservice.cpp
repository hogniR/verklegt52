#include "personservice.h"
#include "person.h"

personService::personService()
{
    personRepository = personRepo();
}

void personService::add(Person p) {
    personRepository.add(p);
}

void personService::printList(){
    personRepository.printList();
}

void personService::sortName(){
    personRepository.sortName();
}
