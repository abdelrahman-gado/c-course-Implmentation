#include <iostream>
#include <string>

using namespace std;

class Account
{
private:
    std::string name;
    double balance;
    
public:
    void set_balance(double balance) 
    { 
        name = "abdou";
        this->balance = balance; // behind the sences this->balance = bal;
    }
    
    double get_balance () const { return balance; }
    
    Account (std::string n, double bal);
    
    void compare(const Account &other) const;
    
    ~Account();
};

Account::Account (std::string n, double bal)
    : name {n}, balance {bal}
{
    cout << "Constructing Account Object for " << name << endl;
}

Account::~Account () 
{
    cout << "Destructor Account Oject for " << name << endl;
}

void Account::compare (const Account &other) const
{
    if (this == &other)
    {
        cout << "The same objects" << endl;
    }
    else
    {
        cout << "different objects" << endl;
    }
    
}

int main() 
{
    const Account obj1 {"Abdou", 1224};
    Account obj2 {"Mhummaed", 500};
    obj1.compare(obj1);
    cout << obj1.get_balance() << endl;

    
    cout << obj2.get_balance() << endl;
    obj2.compare(obj2);
    
    
    return 0;
}