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

        if(inp == "add") {

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
                getline(cin, p.gender);

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

        else if(inp == "delete"){ // if you input "all" then you delete all the list.
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
