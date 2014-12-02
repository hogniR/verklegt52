#include "personrepo.h"

personRepo::personRepo(){

    ifstream inFile ("personList.txt");

        if(inFile.is_open())
        {
            string line, name, gender;
            int birth;

            for(int i = 1; getline(inFile,line); i++)
            {
                if(i == 1)
                    name = line;

                if(i == 2)
                    gender = line;

                if(i == 3)
                    birth = atoi(line.c_str());

                if(i == 4){
                    i = 0;

                    Person p = Person(name, gender, birth,atoi(line.c_str()));
                    personList.push_back(p);
                    }
            }
            inFile.close();
        }
}

personRepo::~personRepo(){
    ofstream file;
    file.open("personList.txt");
    file.clear();
    for(list<Person>::const_iterator it = personList.begin(); it != personList.end(); it++)
    {
        file << (*it).name << "\n" << (*it).gender << "\n" << (*it).birthYear << "\n" << (*it).deathYear << endl;
    }
    file.close();
}

void personRepo::add(Person p) {
    personList.push_back(p);
}

void personRepo::sortName(){
    personList.sort();
}

void personRepo::printList(){
    for(list<Person>::const_iterator it = personList.begin(); it != personList.end(); it++)
    {
        cout << *it << endl;
    }
}

void personRepo::Delete(string name) {

    bool found = false;
    for(std::list<Person>::iterator it = personList.begin(); it != personList.end(); it++)
    {
        if((*it).name == name)
        {
            found = true;
            personList.erase(it);
            break;
        }
    }

    if(found == false)
        cout << "The name was not found." << endl;
}

void personRepo::search(string name) {

    bool found = false;
    for(std::list<Person>::iterator it = personList.begin(); it != personList.end(); it++)
    {
        if((*it).name == name)
        {
            found = true;
            cout << *it << endl;
            break;
        }
    }

    if(found == false)
        cout << "The name was not found." << endl;
}
