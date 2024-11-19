#include "I_Printing.h"
#include <iostream>

using namespace std;

ostream &operator<<(ostream &os, const I_Printing &obj)
{
    obj.print(os);
    return os;
}
