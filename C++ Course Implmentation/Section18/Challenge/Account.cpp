#include "Account.h"

Account::Account (std::string name, double balance)
    : name {name}, balance {balance}
{
    if (balance < 0.0)
        throw IllegalBalanceException();
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
        throw InsufficientFundsException();
        return false;
    }
}

double Account::get_balance () const
{
    return balance;
}

void Account::print(std::ostream &os) const
{
    os << "[Account: " << name << ": " << balance << "]";
}
