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
    return false;
}

void Trust_Account::print(std::ostream &os) const
{
    os << "[Trust_Account: " << name << " : " << balance << " : " << int_rate << "%" << " withdrawals: " << number_withdrawals << "]";
}


