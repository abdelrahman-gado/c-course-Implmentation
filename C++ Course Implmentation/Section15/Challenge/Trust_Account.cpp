#include "Trust_Account.h"

Trust_Account::Trust_Account (std::string name, double balance, double int_rate)
    : Savings_Account (name, balance, int_rate), number_withdrawals {0}
{
    
}

bool Trust_Account::deposit(double amount)
{
    if (amount >= 5000)
    {
        balance += 50.00;
    }
    return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount)
{
    double balance_20_percent = balance * 0.2;
    if (number_withdrawals < MAX_NUM_WITHDRAWAL && amount < balance_20_percent)
    {
        if (Savings_Account::withdraw(amount))
        {
            number_withdrawals++;
            return true;
        }
    }
    else
    {
        return false;
    }
}

Trust_Account &Trust_Account::operator+= (double amount)
{
    if (this->deposit(amount))
        std::cout << "success deposit with += in Trust_Account" << std::endl;
    else
        std::cout << "Fail deposit with -= in the Trust_Account" << std::endl;
        
    return *this;
}

Trust_Account &Trust_Account::operator-= (double amount)
{
    if (this->withdraw(amount))
        std::cout << "success withdraw with += in Trust_Account" << std::endl;
    else
        std::cout << "Fail withdraw with -= in the Trust_Account" << std::endl;
        
    return *this;
}




std::ostream &operator<< (std::ostream &os, const Trust_Account &account)
{
    os << "[Trust_Account: " << account.name << " : " << account.balance << " : " << account.int_rate << "%" << " withdrawals: " << account.number_withdrawals << "]";
    return os;
}

