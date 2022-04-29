#include <iostream>

using namespace std;

class Base
{
private:
    int value;
    
public:
    
    Base () : value {0} { cout << "Base no-args constructor" << endl; }
    Base (int x) : value {x} { cout << "Base (int) constructor" << endl; }
    
    // Copy Constructor
    Base (const Base &other)
        : value {other.value}
    {
        cout << "Base Copy Constructor" << endl;
    }
    
    Base &operator= (const Base &rhs)
    {
        cout << "Base Copy assignment" << endl;
        if (this == &rhs)
        {
            return *this;
        }
        
        value = rhs.value;
        return *this;
    }
    
    ~Base () { cout << "Base Destructor" << endl; }
};


class Derived : public Base
{
private:
    int doubled_value;
    
public:
    
    Derived () : Base {}, doubled_value {0} { cout << "Derived no-args Constructor" << endl; }
    Derived (int x) : Base {x}, doubled_value {x*2} { cout << "Derived (int) constructor" << endl; }
    
    Derived (const Derived &other)
        : Base(other), doubled_value {other.doubled_value}
    {
        cout << "Derived Copy Constructor" << endl;
    }
    
    Derived &operator= (const Derived &rhs)
    {
        cout << "Derived Copy assignment" << endl;
        if (this == &rhs)
        {
            return *this;
        }
        
        Base::operator= (rhs);
        doubled_value = rhs.doubled_value;
        return *this;
    }
    
    ~Derived () { cout << "Derived Destructor" << endl; }
};


int main() 
{
    
//    Base b {100}; // Overload Constructor
//    Base b1 {b}; // Copy Constructor
//    b = b1;      // Copy assignment

    Derived d {100};  // Overload Constructor
    Derived d1 {d};     // Copy Constructor
    d = d1;            // Copy assignment

    return 0;
}