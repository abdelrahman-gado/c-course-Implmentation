#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "Account.h"
#include <iostream>
#include <string>

// Saving Account is a type of Account
// adds an interest rate
// Withdraw - same as a regular account
// Deposit:
//      Account supplied to deposit will be incremented by (account * int_rate/100)
//      and then the updated amount will be deposited.

class Savings_Account : public Account
{
    friend std::ostream &operator<< (std::ostream &os, const Savings_Account &account);
    
private:
    
    static constexpr const char *def_name = "Unnamed Savings Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
    
protected:
    double int_rate;
    
public:
    
    Savings_Account (std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    bool deposit (double amount);
    // Inherits the Account::withdraw methods
    
    Savings_Account &operator+= (double amount);
    Savings_Account &operator-= (double amount);
};

#endif // SAVINGS_ACCOUNT_H
