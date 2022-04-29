#include <iostream>
#include "Mystring.h"
#include <vector>

using namespace std;

int main() 
{
    
    Mystring a {"Hello"}; // overloaded constructor
    Mystring b;  // no-args constructor
    
    b = a;  // copy assignement  b.operator=(a);
    
    b = "This is a test";  // b.operator=(a);  ( "This is a test" is a temporary object)
    
    
    Mystring empty;            // no-args constructor
    Mystring larry {"larry"};   // overloaded constructor
    Mystring stooge {larry};    // copy constructor
    Mystring stooges;            // no-args constructor
    
    empty = stooge;   // copy assignment operator
    
    empty.display();
    larry.display();
    stooge.display();
    empty.display();
    
    stooges = "Larry, Moe and Curly";
    stooges.display();
    
    vector<Mystring> stooges_vec;
    stooges_vec.push_back("Larry");
    stooges_vec.push_back("Moe");
    stooges_vec.push_back("Curly");
    
    cout << "=== Loop 1 ===============" << endl;
    for (const Mystring &s : stooges_vec)
        s.display(); 
        // Larry
        // Moe
        // Curly
        
    
     
    
    for (const Mystring &s : stooges_vec)
        s.display();
        
        // Changed
        // Changed
        // Changed
    
    
    return 0;
}