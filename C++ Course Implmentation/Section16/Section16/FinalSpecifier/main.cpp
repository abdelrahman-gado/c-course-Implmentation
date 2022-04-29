#include <iostream>

using namespace std;

//class Base final
//{
//    
//};
//
//class Derived final : public Base { };
//
//class SubDerived : public Derived { };

class A
{
public:
    virtual void do_something () const
    {
        cout << "A is doing something" << endl;
    }
};

class B : public A
{
public:
    virtual void do_something () const override final
    {
        cout << "B is doing something" << endl;
    } 
    
};

class C : public B
{
public:
    virtual void do_something() const override
    {
        cout << "C is doing something" << endl;
    }
    
};

int main() 
{
    
    return 0;
}