#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "Account.h"
#include <string>
#include <iostream>

class Checking_Account : public Account
{
    
private:
    static constexpr double WITHDRAWAL_FEE = 1.50;
    static constexpr const char *DEF_NAME = "Unnamed Checking Account";
    static constexpr double DEF_BALANCE = 0.0;
    
public:
    Checking_Account(std::string name = DEF_NAME, double balance = DEF_BALANCE);
    virtual bool withdraw(double amount) override;
    virtual bool deposit(double amount) override;
    virtual void print(std::ostream &os) const override;
    
    
    virtual ~Checking_Account() = default;

};

#endif // CHECKING_ACCOUNT_H
