#include "consoleui.h"

using namespace std;

ConsoleUI::ConsoleUI()
{
    personServ = personService();
}


void ConsoleUI::start() {
    string inp;
    cout << "Welcome" << endl;
    do{

        cout << "The commands are:\t add \t print \t quit" << endl;
        cin >> inp;

        if(inp == "add") {
            Person p = Person();
            cin >> p.name >> p.gender >> p.birthYear >> p.deathYear;

            personServ.add(p);
        }

        else if(inp == "print"){
            int option;
            cout << "Please enter a number to sort by (1) Name, (2) Birth Year or (3) Year of death" << endl;
            cin >> option;

            if(option == 1)
            {
                personServ.sortName();
            }
            /*else if(option == 2){
                personServ.sortByear();
            }
            else if(option == 3){
                personServ.sortDyear();
            }
            */

            personServ.printList();
        } else{
            cout << "No such command" << endl;
        }
    }while(inp != "quit");
}
