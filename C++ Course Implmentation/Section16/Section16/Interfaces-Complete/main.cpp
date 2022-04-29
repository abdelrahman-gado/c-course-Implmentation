#include <iostream>

using namespace std;

class I_Printable
{
    friend std::ostream &operator<< (std::ostream &os, const I_Printable &obj);
    
public:
    
    virtual void print(std::ostream &os) const = 0;
    virtual ~I_Printable() { }
};


std::ostream &operator<< (std::ostream &os, const I_Printable &obj)
{
    obj.print(os);   // dynamic binding
    return os;
}


class Account : public I_Printable
{
public:
    virtual void withdraw (double amount)
    {
        cout << "In Account::withdraw" << endl;
    }
    
    virtual void print (std::ostream &os) const override
    {
        os << "Account display";
    }
    
    virtual ~Account() { }
};


class Savings : public Account
{
public:
    virtual void withdraw(double)
    {
        cout << "In Savings::withdraw" << std::endl;
    }
    
    virtual void print (std::ostream &os) const override
    {
        os << "Savings display";
    }
    
    virtual ~Savings() { }
};

class Checking : public Account
{
public:
    virtual void withdraw(double)
    {
        cout << "In Checking::withdraw" << std::endl;
    }
    
    virtual void print (std::ostream &os) const override
    {
        cout << "Checking display";
    }
    
    virtual ~Checking() { }
};

class Trust : public Account
{
public:
    virtual void withdraw(double)
    {
        cout << "In Trust::withdraw" << std::endl;
    }
    
    virtual void print (std::ostream &os) const override
    {
        os << "Trust display";
    }
    
    virtual ~Trust() { }
};

class Dog : public I_Printable
{
public:
    virtual void print (std::ostream &os) const override
    {
        os << "Woof Woof";
    }
    
};

void print (I_Printable &obj)
{
    cout << obj << endl;
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

    Dog *dog = new Dog();
    cout << *dog << endl;
    
    print(*dog);
    
    Account *ptr1 = new Account();
    cout << *ptr1 << endl;
    
    
    Account *ptr2 = new Checking();
    cout << *ptr2 << endl;
    

    return 0;
}