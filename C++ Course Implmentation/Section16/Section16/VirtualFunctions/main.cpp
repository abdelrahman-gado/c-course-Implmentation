#include <iostream>

using namespace std;

class Account
{
public:
    virtual void withdraw (double amount) const
    {
        cout << "Account::withdraw" << endl;
    }
    
};

class Savings : public Account
{
public:
    virtual void withdraw (double amount) const
    {
        cout << "Savings::withdraw" << endl;
    }
    
};

class Checking : public Account
{
public:
    virtual void withdraw (double amount) const
    {
        cout << "Checking::withdraw" << endl;
    }
};

class Trust : public Savings
{
public:
    virtual void withdraw (double amount) const
    {
        cout << "Trust::withdraw" << endl;
    }
};



int main() 
{
    cout << "\n === Pointers ====" << endl;
    Account *p1 = new Account();
    Account *p2 = new Savings();
    Account *p3 = new Checking();
    Account *p4 = new Trust();
    
    p1->withdraw(1000);
    p2->withdraw(1000);
    p3->withdraw(1000);
    p4->withdraw(1000);
    
    cout << "\n === Clean Up ====" << endl;
    
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    
    
    return 0;
}