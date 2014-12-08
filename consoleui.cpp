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
    do
    {
        cout << endl << "The commands are: add, print, search, quit, connect" << endl;
        cin >> inp;

        if(inp == "add")
        {
            add();
        }
        else if(inp == "print")
        {
            print();
        }
        else if(inp == "search")
        {
            search();
        }
        else if(inp == "connect")
        {
            connect();
        }
        else if(inp != "quit")
        {
            cout << "No such command" << endl;
        }
    }while(inp != "quit");
}

void ConsoleUI::add()
{
    string inp;

    cout << "Do you want to add a (p)erson or a (c)omputer?: ";
    cin >> inp;

    if(inp == "p")
        addPerson();
    else if(inp == "c")
        addComputer();
}

void ConsoleUI::addPerson()
{
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
        cin.sync();;
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

void ConsoleUI::addComputer()
{
    Computer c = Computer();

    cout << "Enter name: ";
    cin.sync();
    getline(cin, c.name);

    cout << "Enter Year: ";
    cin >> c.year;

    cout << "Enter type: ";
    cin >> c.type;

    cout << "Was it made? (1 or 0): ";
    cin >> c.made;

   computerServ.add(c);
}

void ConsoleUI::print()
{
    string inp;

    cout << "Do you want to print a list of (p)ersons or (c)omputers?: ";
    cin >> inp;

    if(inp == "p")
        printPersons();
    else if(inp == "c")
        printComputers();
}

void ConsoleUI::printPersons()
{
    int option;
    cout << "Please enter a number to sort by (1) Name, (2) Gender, (3) Birth Year or (4) Year of death" << endl;
    cin >> option;

    while(option < 1 || option > 4)
    {
        cout << "Invalid option selected, please try again." << endl;
        cin >> option;
    }
    QSqlQuery query = personServ.printList(option);
    while(query.next())
    {
        cout << "Name:          " << query.value(0).toString().toStdString() << endl;
        cout << "Gender:        " << query.value(1).toString().toStdString() << endl;
        cout << "Birth year:    " << query.value(2).toString().toStdString() << endl;
        cout << "Year of death: " << query.value(3).toString().toStdString() << endl;
        cout << "Computer:      " << query.value(5).toString().toStdString() << endl;
        cout << endl;
    }
}

void ConsoleUI::printComputers()
{
    int option;
    cout << "Please enter a number to sort by (1) Name, (2) Year, (3) Type or (4) if it was Made" << endl;
    cin >> option;

    while(option < 1 || option > 4)
    {
        cout << "Invalid option selected, please try again." << endl;
        cin >> option;
    }
    QSqlQuery query = computerServ.printList(option);
    while(query.next())
    {
        cout << "Name:          " << query.value(0).toString().toStdString() << endl;
        cout << "Year:          " << query.value(1).toString().toStdString() << endl;
        cout << "Type:          " << query.value(2).toString().toStdString() << endl;
        string made;
        if(query.value(3) == 0)
            made = "No";
        else
            made = "Yes";

        cout << "It was made:   " << made << endl;
        cout << "Creator:       " << query.value(5).toString().toStdString() << endl;
        cout << endl;
    }
}

void ConsoleUI::search()
{
    string inp;

    cout << "Do you want to search for a (p)erson or for a (c)omputer?: ";
    cin >> inp;

    if(inp == "p")
        searchPerson();
    else if(inp == "c")
        searchComputer();
}

void ConsoleUI::searchPerson()
{
    string name;
    cout << "Please enter a name of a person to search: ";
    cin.ignore();
    getline(cin, name);
    cin.clear();

    QSqlQuery query = personServ.search(name);
    if(query.next())
    {
        query.previous();
        while(query.next())
        {
            cout << endl;
            cout << "Name:          " << query.value("Name").toString().toStdString() << endl;
            cout << "Gender:        " << query.value("Gender").toString().toStdString() << endl;
            cout << "Birth year:    " << query.value("birthYear").toString().toStdString() << endl;
            cout << "Year of death: " << query.value("deathYear").toString().toStdString() << endl;
            cout << endl;
        }
    }
    else
    {
        cout << endl;
        cout << "No matches found" << endl;
    }
}

void ConsoleUI::searchComputer()
{
    string name;
    cout << "Please enter a name of a computer to search: ";
    cin.ignore();
    getline(cin, name);
    cin.clear();

    QSqlQuery query = computerServ.search(name);
    if(query.next())
    {
        query.previous();
        while(query.next())
        {
            cout << "Name:          " << query.value("Name").toString().toStdString() << endl;
            cout << "Year:          " << query.value("Year").toString().toStdString() << endl;
            cout << "Type:          " << query.value("Type").toString().toStdString() << endl;
            string made;
            if(query.value("Made") == 0)
                made = "No";
            else
                made = "Yes";

            cout << "It was made:   " << made << endl;
            cout << endl;
        }
    }
    else
    {
        cout << endl;
        cout << "No matches found" << endl;
    }
}

void ConsoleUI::connect()
{
    string name, computer;
    cout << "Please enter a name to connect: ";
    cin.ignore();
    getline(cin, name);
    cin.clear();

    cout << "Please enter a computer to connect: ";
    getline(cin, computer);
    cin.clear();

    if(personServ.connect(name, computer))
        cout << "Connected." << endl;
    else
        cout << "Not connected." << endl;
}
