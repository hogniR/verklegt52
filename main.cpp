#include <iostream>
#include "manager.h"
#include <list>

using namespace std;

int main()
{
    list<Person> list1;
    Person p = Person("Hogni", "male", 1990, 2000);
    list1.push_back(p);
    for(list<Person>::const_iterator i = list1.begin(); i != list1.end(); i++){
        cout << *i << endl;
    }
    return 0;
}
