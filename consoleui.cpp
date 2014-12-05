#include "consoleui.h"

using namespace std;

ConsoleUI::ConsoleUI()
{
    //personServ = personService();
}

void ConsoleUI::start()
{
    string inp;
    ifstream menu ("forsida.txt");
    cout << menu.rdbuf() << endl;
    do{

        cout << endl << "The commands are: add, print, delete, search, quit" << endl;
        cin >> inp;

        if(inp == "add"){
            add();
        }
        else if(inp == "print"){
            print();
        }
        else if(inp == "search"){
            search();
        }
        else if(inp != "quit"){
            cout << "No such command" << endl;
        }
    }while(inp != "quit");
}

void ConsoleUI::add(){
    Person p = Person();
    cout << "Enter name: ";
    cin.sync();
    getline(cin, p.name);

    //makes the first letter BIG.
    p.name[0] = toupper(p.name[0]);
    for(unsigned int i = 1; i < p.name.length(); i++)
    {
        if(p.name[i-1] != ' ')p.name[i] = tolower(p.name[i]);
        if(p.name[i] == ' ')p.name[i+1] = toupper(p.name[i+1]);
    }

    do // you can only enter male or female
    {
        cout << "Enter gender: ";
        cin.ignore();
        getline(cin, p.gender);
        cin.clear();

        p.gender[0] = toupper(p.gender[0]);
        if(p.gender.length() <= 5)
            for(unsigned int i = 1; i < p.gender.length(); i++)p.gender[i] = tolower(p.gender[i]);

        if(p.gender == "Male" || p.gender == "Female") break;
            cout << "Invalid input, try again." << endl;
    }while(p.gender != "male" || p.gender != "female");

    do //you can only enter valid birthyear.
    {
        cout << "Enter birthyear: ";
        cin >> p.birthYear;

        if(p.birthYear >= 0)break;
        cout << "Invalid year, try again." << endl;

    }while(p.birthYear < 0);

    do
    {
        cout << "Enter deathyear: ";
        cin >> p.deathYear;
        if(p.deathYear >= p.birthYear) break;
            cout << "A person can not die before it is born, please try again." << endl;

    }while(p.deathYear < p.birthYear);

    personServ.add(p);
}

void ConsoleUI::print(){
    int option;

    cout << "Please enter a number to sort by (1) Name, (2) Gender, (3) Birth Year or (4) Year of death" << endl;

    personServ.printList();

}

void ConsoleUI::search(){
    string name;
    cout << "Please enter a name to search: ";
    cin.ignore();
    getline(cin, name);
    cin.clear();

    personServ.search(name);
}
