#include "personservice.h"
#include "person.h"

personService::personService()
{
    //personRepository = personRepo();
}

void personService::add(Person p){
    personRepository.add(p);
}

void personService::add_computer(Computer c){
    personRepository.add_computer(c);
}

void personService::printList(){
    personRepository.printList();
}

void personService::sortName(){
    personRepository.sortName();
}

void personService::search(string name){
    personRepository.search(name);
}
