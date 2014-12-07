#include "computerservice.h"

void computerService::add(Computer c)
{
    computerRepository.add(c);
}

QSqlQuery computerService::printList(int option)
{
    return computerRepository.printList(option);
}

QSqlQuery computerService::search(string name)
{
    return computerRepository.search(name);
}

