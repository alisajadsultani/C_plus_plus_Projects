#include "Account.h"

Account::Account(){};

int Account::deposit(int amount)
{
    return balance += amount;
}

int Account::withdraw(int amount)
{
    if(balance - amount > 0)
    {
        balance -= amount;
    }else{
        return false;
    }
}

void Account::print(std::ostream &os) const
{
    os << "[ Balance: " << balance << " ]" << std::endl;
}


