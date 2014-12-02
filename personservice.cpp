#include "personservice.h"
#include "person.h"

personService::personService()
{
    //personRepository = personRepo();
}

void personService::add(Person p){
    personRepository.add(p);
}

void personService::printList(){
    personRepository.printList();
}

void personService::sortName(){
    personRepository.sortName();
}

void personService::Delete(string name){
    personRepository.Delete(name);
}

void personService::search(string name){
    personRepository.search(name);
}

void personService::sortGender(){
    personRepository.sortGender();
}

void personService::sortByear(){
    personRepository.sortByear();
}

void personService::sortDyear(){
    personRepository.sortDyear();
}
