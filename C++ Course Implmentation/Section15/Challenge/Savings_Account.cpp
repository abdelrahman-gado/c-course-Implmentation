#include "Savings_Account.h"

Savings_Account::Savings_Account (std::string name, double balance, double int_rate)
    : Account {name, balance}, int_rate {int_rate}
{
        
}

bool Savings_Account::deposit (double amount)
{
    amount = amount + (amount * (int_rate/100));
    return Account::deposit (amount);
}

Savings_Account &Savings_Account::operator+= (double amount)
{
    if(this->deposit(amount))
        std::cout << "success deposit with += in Savings_Account" << std::endl;
    else
        std::cout << "Fail deposit with += in Savings_Account" << std::endl;
    return *this;
}

Savings_Account &Savings_Account::operator-= (double amount)
{
    if(this->withdraw(amount))
        std::cout << "success withdraw with += in Savings_Account" << std::endl;
    else
        std::cout << "Fail withdraw with += in Savings_Account" << std::endl;
    return *this;
}


std::ostream &operator<< (std::ostream &os, const Savings_Account &account)
{
    os << "[Savings_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
    return os;
}



