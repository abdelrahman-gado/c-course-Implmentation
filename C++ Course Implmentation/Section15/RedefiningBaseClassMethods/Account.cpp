#include "Account.h"

Account::Account ()
    : balance {0.0}
{
    
}

Account::Account (double balance)
    : balance {balance}
{
    
    
}


void Account::deposit (double amount)
{
    balance += amount;
}

void Account::withdraw (double amount)
{
    if (balance-amount >= 0)
        balance -= amount;
    else
        std::cout << "Insuficient Funds" << std::endl;
    
}


std::ostream &operator<< (std::ostream &os, const Account &account)
{
    os << "Account Balance: " << account.balance;
    return os;
}
