#ifndef TRUST_ACCOUNT_H
#define TRUST_ACCOUNT_H

#include "Savings_Account.h"
#include <string>
#include <iostream>

class Trust_Account : public Savings_Account
{
private:
    static constexpr double DEPOSIT_BONUS = 50.00;
    static constexpr int MAX_NUM_WITHDRAWAL = 3;
    static constexpr const char *DEF_NAME = "Unnamed Account";
    static constexpr double DEF_BALANCE = 0.0;
    static constexpr double DEF_INT_RATE = 0.0;
    
protected:
    int number_withdrawals;
    
public:
    Trust_Account(std::string name = DEF_NAME, double balance = DEF_BALANCE, double int_rate = DEF_INT_RATE);
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual void print(std::ostream &os) const override;
    
    virtual ~Trust_Account() = default;
    
};

#endif // TRUST_ACCOUNT_H
