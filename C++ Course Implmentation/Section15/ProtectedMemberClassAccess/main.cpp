#include <iostream>

using namespace std;

class Base
{
    // Note friends of the Base class have access to all.
public:
    int a {0};
    void display() { std::cout << a << ", " << b << ", " << a << std::endl; } // member method have access to all

protected:
    int b {0};
    
private:
    int c {0};
    
};


class Derived : public Base
{
    // Note friends of the Drived class have only access to what Derived has access to.
    
    // a is public
    // b is protected
    // c is not accessible
    
public:
    void access_base_members ()
    {
        a = 100; // OK
        b = 200; // OK
       // c = 300; // Compiler Error -- > not accesible
    }
    
};


int main() 
{
    cout << "=== Base member access from base objects ========" << endl;
    Base base;
    base.a = 100; // OK
   // base.b = 200; // Compiler Error ---> protected
   // base.c = 300; // Compiler Error ---> private
    
    cout << "=== Base class member access from Derived objects =======" << endl;
    Derived d;
    d.a = 100; // OK
   // d.b = 200; // Compiler Error ---> protected
   // d.c = 300; // Compiler Error ---> not accessible
    
    return 0;
}