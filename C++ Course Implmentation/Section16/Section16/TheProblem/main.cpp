#include <iostream>
#include <memory>

using namespace std;


class Base
{
public:
    void say_hello () const
    {
         cout << "Hello - I'm a Base class object" << endl;
    }
    
};

class Derived : public Base
{
public:
    void say_hello() const
    {
        
        cout << "Hello - I'm a Derived class object" << endl;
    }
};

void greetings (const Base &b)
{
    cout << "Greetings: ";
    b.say_hello();
}

int main() 
{
    
    Base b;
    b.say_hello();
    
    Derived d;
    d.say_hello();
    
    greetings(b);
    greetings(d);
    
    Base *ptr = new Derived();
    ptr->say_hello();
    
    delete ptr;
    
    
    std::unique_ptr<Base> ptr1 = std::make_unique<Derived>();
    ptr1->say_hello();
    
    
    return 0;
}