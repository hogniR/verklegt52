#ifndef COMPUTERSERVICE_H
#define COMPUTERSERVICE_H

#include "computer.h"
#include "computerrepo.h"

class computerService
{
private:
    computerRepo computerRepository;
public:
    void add(Computer c);
    QSqlQuery printList(int option);
    QSqlQuery search(string name);
};

#endif // COMPUTERSERVICE_H
