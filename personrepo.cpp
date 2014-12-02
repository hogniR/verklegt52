#include "personrepo.h"

personRepo::personRepo()
{
    personList = list<Person>();
}

personRepo::~personRepo()
{
    ofstream file;
    file.open("personList.txt");
    file.clear();
    for(list<Person>::const_iterator it = personList.begin(); it != personList.end(); it++)
    {
        file << *it << endl;
    }
    file.close();
}

void personRepo::add(Person p)
{
    personList.push_back(p);
}

bool compareName(const Person lhs, const Person rhs){
    return lhs.name < rhs.name;
}

bool compareGender(const Person lhs, const Person rhs){
    return lhs.gender < rhs.gender;
}

bool compareBirthyear(const Person lhs, const Person rhs){
    return lhs.birthYear < rhs.birthYear;
}

bool compareDeathyear(const Person lhs, const Person rhs){
    return lhs.deathYear < rhs.deathYear;
}

void personRepo::sortName()
{
    personList.sort(compareName);
}

void personRepo::sortGender()
{
    personList.sort(compareGender);
}

void personRepo::sortByear()
{
    personList.sort(compareBirthyear);
}

void personRepo::sortDyear()
{
    personList.sort(compareDeathyear);
}

void personRepo::printList()
{
    for(list<Person>::const_iterator it = personList.begin(); it != personList.end(); it++)
    {
        cout << *it << endl;
    }
}

