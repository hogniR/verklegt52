#include "personrepo.h"

personRepo::personRepo()
{
    personList = list<Person>();
}

personRepo::~personRepo(){
    ofstream file;
    file.open("personList.txt");
    file.clear();
    for(list<Person>::const_iterator it = personList.begin(); it != personList.end(); it++)
    {
        file << *it << endl;
    }
    file.close();
}

void personRepo::add(Person p) {
    personList.push_back(p);
}
void personRepo::sortName(){
    personList.sort();
}

void personRepo::printList(){
    for(list<Person>::const_iterator it = personList.begin(); it != personList.end(); it++)
    {
        cout << *it << endl;
    }
}
