#include <iostream>

using namespace std;

class Account
{
    friend std::ostream &operator<<(std::ostream &os, const Account &account);
public:
    virtual void withdraw (double amount)
    {
        cout << "In Account::withdraw" << endl;
    }
    virtual ~Account() { }
};

std::ostream &operator<< (std::ostream &os, const Account &account)
{
    os << "Account display";
    return os;
}

class Savings : public Account
{
    friend std::ostream &operator<< (std::ostream &os, const Savings &account);
public:
    virtual void withdraw(double)
    {
        cout << "In Savings::withdraw" << std::endl;
    }
    virtual ~Savings() { }
};

std::ostream &operator<< (std::ostream &os, const Savings &account)
{
    os << "Savings display";
    return os;
}

class Checking : public Account
{
    friend std::ostream &operator<< (std::ostream &os, const Checking &account);
public:
    virtual void withdraw(double)
    {
        cout << "In Checking::withdraw" << std::endl;
    }
    virtual ~Checking() { }
};

std::ostream &operator<< (std::ostream &os, const Checking &account)
{
    os << "Checking display";
    return os;
}

class Trust : public Account
{
    friend std::ostream &operator<< (std::ostream &os, const Trust &account);
public:
    virtual void withdraw(double)
    {
        cout << "In Trust::withdraw" << std::endl;
    }
    virtual ~Trust() { }
};

std::ostream &operator<< (std::ostream &os, const Trust &account)
{
    os << "Trust display";
    return os;
}


int main() 
{
//    Account a;
//    cout << a << endl;
//    
//    Checking c;
//    cout << c << endl;
//    
//    Savings s;
//    cout << s << endl;
//    
//    Trust t;
//    cout << t << endl;

    Account *ptr1 = new Account();
    cout << *ptr1 << endl;
    
    
    Account *ptr2 = new Checking();
    cout << *ptr2 << endl;

    
    return 0;
}