#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "Account.h"
#include <string>
#include <iostream>

class Checking_Account : public Account
{
    friend std::ostream &operator<< (std::ostream &os, const Checking_Account &account);
    
private:
    static constexpr double WITHDRAWAL_FEE = 1.50;
    static constexpr const char *DEF_NAME = "Unnamed Checking Account";
    static constexpr double DEF_BALANCE = 0.0;
    
public:
    Checking_Account(std::string name = DEF_NAME, double balance = DEF_BALANCE);
    bool withdraw(double amount);
    
    
    Checking_Account &operator+= (double amount);
    Checking_Account &operator-= (double amount);

};

#endif // CHECKING_ACCOUNT_H
