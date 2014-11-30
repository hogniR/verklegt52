#include "personrepo.h"

personRepo::personRepo(){
    personList = list<Person>();
    ifstream inFile ("personList.txt");
        if(inFile.is_open())
        {
            while(!inFile.eof())
            {
                Person p = Person();
                inFile >> p.gender >> p.birthYear >> p.deathYear;
                personList.push_back(p);
            }
            inFile.close();
        }
}

personRepo::~personRepo(){
    ofstream file;
    file.open("personList.txt");
    file.clear();
    for(list<Person>::const_iterator it = personList.begin(); it != personList.end(); it++)
    {
        file << (*it).name << " " << (*it).gender << " " << (*it).birthYear << " " << (*it).deathYear << endl;
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

void personRepo::Delete(string name) {

    for(std::list<Person>::iterator it = personList.begin(); it != personList.end(); it++)
    {
        if((*it).name == name)
        {
            personList.erase(it);
            break;
        }
    }
}
