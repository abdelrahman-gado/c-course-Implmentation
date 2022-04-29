#include <iostream>

using namespace std;

class Account
{
public:
    virtual void withdraw (double amount) const
    {
        cout << "Account::withdraw" << endl;
    }
    
    virtual ~Account() { }
};

class Savings : public Account
{
public:
    virtual void withdraw (double amount) const override
    {
        cout << "Savings::withdraw" << endl;
    }
    
    virtual ~Savings() { }
};

class Checking : public Account
{
public:
    virtual void withdraw (double amount) const override
    {
        cout << "Checking::withdraw" << endl;
    }
    
    virtual ~Checking() { }
};

class Trust : public Savings
{
public:
    virtual void withdraw (double amount) const override
    {
        cout << "Trust::withdraw" << endl;
    }
    
    virtual ~Trust() { }
};

void do_withdraw (Account &account, double amount)
{
    account.withdraw(1000);
}

int main() 
{
    Account a;
    Account &ref = a;
    ref.withdraw(1000);   // dynamic binding -- Account::withdraw
    
    Trust t;
    Account &ref1 = t;
    ref1.withdraw(1000); // dynamic binding -- Trust::withdraw
    
    Account a1;
    Savings a2;
    Checking a3;
    Trust a4;
    
    do_withdraw(a1, 1000);  // dynamic binding   Account::withdraw
    do_withdraw(a2, 1000);  // dynamic binding   Savings::withdraw
    do_withdraw(a3, 1000);  // dynamic binding   Checking::withdraw
    do_withdraw(a4, 1000);  // dynamic binding   Trust::withdraw
    
    
    return 0;
}