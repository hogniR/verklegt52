#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>

using namespace std;

class Computer
{
public:
    Computer();

    string name;
    int year;
    string type;
    bool made;
    string creator;
};

#endif // COMPUTER_H
