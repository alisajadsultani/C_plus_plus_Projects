#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "I_Printing.h"
#include <iostream>

class Account : public I_Printing
{
public:
    int balance = 0;

    Account();
    virtual int deposit(int amount);
    virtual int withdraw(int amount);
    virtual void print(std::ostream &os) const override;
    virtual ~Account() = default;

};

#endif // ACCOUNT_H
