#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include <string>
#include <iostream>
#include "personservice.h"

class ConsoleUI
{
public:
    ConsoleUI();
    void start();
private:
    personService personServ;
};


#endif // CONSOLEUI_H
