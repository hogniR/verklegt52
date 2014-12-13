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
    bool contains(string str);

    string name;
    string gender;
    int birthYear;
    int deathYear;
    string computer;
};

ostream& operator<< (ostream& out, const Person& p);

#endif // PERSON_H
