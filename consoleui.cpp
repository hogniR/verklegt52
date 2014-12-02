#include "consoleui.h"

using namespace std;

ConsoleUI::ConsoleUI()
{
    //personServ = personService();
}

void ConsoleUI::start()
{
    string inp;
    cout << "Welcome" << endl;
    do{

        cout << "The commands are:\t add \t print \t delete \t search \t quit" << endl;
        cin >> inp;

        if(inp == "add") {
            Person p = Person();
            cout << "Enter name: ";
            cin.sync();
            getline(cin, p.name);
            cout << "Enter gender: ";
            getline(cin, p.gender);
            cout << "Enter birthyear: ";
            cin >> p.birthYear;
            cout << "Enter deathyear: ";
            cin >> p.deathYear;

            personServ.add(p);
        }

        else if(inp == "print"){
            int option;

            cout << "Please enter a number to sort by (1) Name, (2) Gender, (3) Birth Year or (4) Year of death" << endl;
            cin >> option;

            if(option == 1)
            {
                personServ.sortName();
            }
            else if(option == 2){
                personServ.sortGender();
            }
            else if(option == 3){
                personServ.sortByear();
            }
            else if(option == 4){
                personServ.sortDyear();
            }

            personServ.printList();
        }

        else if(inp == "delete"){
            string name;
            cout << "Please enter a name to delete: ";
            cin.sync();
            getline(cin, name);

            personServ.Delete(name);
        }

        else if(inp == "search"){
            string name;
            cout << "Please enter a name to search: ";
            cin.sync();
            getline(cin, name);

            personServ.search(name);
        }

        else if(inp != "quit"){
            cout << "No such command" << endl;
            }
    }while(inp != "quit");
}
