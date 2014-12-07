#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include <string>
#include <iostream>
#include <fstream>
#include "personservice.h"
#include "computerservice.h"

class ConsoleUI
{
public:
    ConsoleUI();
    //starts the interface for the software
    void start();

    //functions to edit and display person list
    void add();
    void addPerson();
    void addComputer();

    void print();
    void printPersons();
    void printComputers();

    void search();
    void connect();
    void searchPerson();
    void searchComputer();

private:
    personService personServ;
    computerService computerServ;
};


#endif // CONSOLEUI_H
