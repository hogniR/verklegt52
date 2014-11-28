#include "consoleui.h"

using namespace std;

ConsoleUI::ConsoleUI()
{
    personServ = personService();
}


void ConsoleUI::start() {
    string inp;
    cout << "Welcome!!\nThe commands are:\t add" << endl;
    cin >> inp;

    if(inp == "add") {
        Person p = Person();
        //cin >> c.color >> c.manufacturer >> c.model;

        personServ.add(p);
    }
}
