#include "person.h"

Person::Person()
{
    birthYear = 0;
    deathYear = 0;
    gender = "";
    name = "";
    computer = "";
}

Person::Person(string n, string g, int byear, int dyear)
{
    name = n;
    gender = g;
    birthYear = byear;
    deathYear = dyear;
}

ostream& operator<< (ostream& out, const Person& p)
{
    out << "Name:        " << p.name << endl;
    out << "Gender:      " << p.gender << endl;
    out << "Birth Year:  " << p.birthYear << endl;
    out << "Death Year:  " << p.deathYear << endl;
    return out;
}

