#include "I_Printing.h"
#include <iostream>

std::ostream &operator<<(std::ostream &os, const I_Printing &obj)
{
    obj.print(os);
    return os;
}
