#include "Account.h"

Account::Account (std::string name, double balance)
    : name {name}, balance {balance}
{
    
}

bool Account::deposit (double amount)
{
    if (amount > 0)
    {
        balance += amount;
        return true;
    }
    else
    {
        return false;
    }
}


bool Account::withdraw (double amount)
{
    if (balance-amount >= 0)
    {
        balance -= amount;
        return true;
    }
    else
    {
        return false;
    }
}

double Account::get_balance () const
{
    return balance;
}

void operator+= (Account &account, double amount)
{
    if (account.deposit(amount))
        std::cout << "success deposit with += in Account" << std::endl;
    else
        std::cout << "Fail deposit with += in Account" << std::endl;
}


void operator-= (Account &account, double amount)
{
    if (account.withdraw(amount))
        std::cout << "success withdraw with -= in Account" << std::endl;
    else
        std::cout << "Fail withdraw with -= in Account" << std::endl;
}


std::ostream &operator<< (std::ostream &os, const Account &account)
{
    os << "[Account: " << account.name << ": " << account.balance << "]";
    return os;
}