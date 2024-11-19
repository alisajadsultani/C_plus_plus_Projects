#ifndef I_PRINTING_H
#define I_PRINTING_H
#include <iostream>
#include <string>

using namespace std;

class I_Printing
{
    friend ostream &operator<<(ostream &os, const I_Printing &obj);
public:
    virtual void print(ostream &os) const = 0;
    virtual ~I_Printing() = default;

};

#endif // I_PRINTING_H
