#ifndef PERSONREPO_H
#define PERSONREPO_H

#include <list>
#include <functional>
#include <fstream>
#include <string>
#include <cstdlib>
#include <Qtsql>

#include "person.h"
#include "computer.h"

using namespace std;

class personRepo
{
private:
    QSqlDatabase db;
public:
    personRepo();

    void add(Person p);
    void add_computer(Computer c);
    void printList(int option);
    void search(string name);

};

#endif // PERSONREPO_H
