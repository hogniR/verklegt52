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

void personService::printList(int option){
    personRepository.printList(option);
}


void personService::search(string name){
    personRepository.search(name);
}

void personService::connect(string name, string computer){
    personRepository.connect(name, computer);
}
