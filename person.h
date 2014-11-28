#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    Person();
    Person(string n, string g, int byear, int dyear);

    string name;
    string gender;
    int birthYear;
    int deathYear;
};

ostream& operator<< (ostream& out, const Person& p);
bool operator<(const Person& lhs, const Person& rhs);

#endif // PERSON_H
