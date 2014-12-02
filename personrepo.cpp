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

void personRepo::add(Person p)
{
    personList.push_back(p);
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

bool compareName(const Person lhs, const Person rhs){
    return lhs.name < rhs.name;
}

bool compareGender(const Person lhs, const Person rhs){
    return lhs.gender < rhs.gender;
}

bool compareBirthyear(const Person lhs, const Person rhs){
    return lhs.birthYear < rhs.birthYear;
}

bool compareDeathyear(const Person lhs, const Person rhs){
    return lhs.deathYear < rhs.deathYear;
}

void personRepo::sortName()
{
    personList.sort(compareName);
}

void personRepo::sortGender()
{
    personList.sort(compareGender);
}

void personRepo::sortByear()
{
    personList.sort(compareBirthyear);
}

void personRepo::sortDyear()
{
    personList.sort(compareDeathyear);
}
