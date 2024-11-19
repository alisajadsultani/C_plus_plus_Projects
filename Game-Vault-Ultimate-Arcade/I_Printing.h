#ifndef I_PRINTING_H
#define I_PRINTING_H
#include <iostream>
#include <string>

class I_Printing
{
    friend std::ostream &operator<<(std::ostream &os, const I_Printing &obj);
public:
    virtual void print(std::ostream &os) const = 0;
    virtual ~I_Printing() = default;
};

#endif // I_PRINTING_H

