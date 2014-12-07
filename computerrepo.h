#ifndef COMPUTERREPO_H
#define COMPUTERREPO_H

#include <Qtsql>
#include "computer.h"

class computerRepo
{
private:
    QSqlDatabase db;

public:
    computerRepo();

    void add(Computer c);
    QSqlQuery printList(int option);
    QSqlQuery search(string name);
};

#endif // COMPUTERREPO_H
