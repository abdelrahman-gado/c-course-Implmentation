#include "Checking_Account.h"


Checking_Account::Checking_Account(std::string name, double balance)
    : Account(name, balance)
{
    
}


bool Checking_Account::withdraw (double amount)
{
    amount += WITHDRAWAL_FEE;
    return Account::withdraw(amount);
}

Checking_Account &Checking_Account::operator+= (double amount)
{
    if (this->deposit(amount))
        std::cout << "success deposit with += in Checking_Account" << std::endl;
    else
        std::cout << "Fail deposit with += in Checking_Account" << std::endl;
        
    return *this;
}

Checking_Account &Checking_Account::operator-= (double amount)
{
    if (this->withdraw(amount))
        std::cout << "success withdraw with -= in Checking_Account" << std::endl;
    else
        std::cout << "Fail withdraw with -= in Checking_Account" << std::endl;
    
    return *this;
}


std::ostream &operator<< (std::ostream &os, const Checking_Account &account)
{
    os << "[Checking_Account: " << account.name << " : " << account.balance << "]";
    return os;
}