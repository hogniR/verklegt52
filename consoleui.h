#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include <string>
#include <iostream>
#include "personservice.h"

class ConsoleUI
{
public:
    ConsoleUI();
    //starts the interface for the software
    void start();

    //functions to edit and display person list
    void add();
    void print();
    void deletePerson();
    void search();
private:
    personService personServ;
};


#endif // CONSOLEUI_H
