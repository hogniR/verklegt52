#ifndef PERSONREPO_H
#define PERSONREPO_H

#include <list>
#include <functional>
#include <fstream>
#include <string>
#include <cstdlib>
#include <Qtsql>

#include "person.h"

using namespace std;

class personRepo
{
private:
    list<Person> personList;
public:
    personRepo();
    ~personRepo();
    QSqlDatabase db;

    void add(Person p);
    void printList();
    void Delete(string name);
    void search(string name);

    void sortName();
    void sortGender();
    void sortByear();
    void sortDyear();
};



#endif // PERSONREPO_H
