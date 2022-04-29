#include <iostream>
#include <vector>
#include "Mystring.h"

using namespace std;


int main() 
{
    
    Mystring a {"Hello"};
    a = Mystring {"Halo"};  //  R-value (temporary unnamed object)
    a = "Bonjour";
    
    Mystring empty;               // no-args Constructor
    Mystring larry {"larry"};     // overloaded Constructor
    Mystring stooge {larry};        // Copy Constructor
    Mystring stooges;               // no-args Constructor
    
    empty = stooge;                // Copy assignment
    
    empty = "Funny";                // Move assignment
    
    empty.display();
    larry.display();
    stooge.display();
    empty.display();
    
    stooges = "Larry, Moe and Curly";       // move assignment
    stooges.display();
    
    vector<Mystring> stooges_vec;
    stooges_vec.push_back("Larry");  // Move Constructor
    stooges_vec.push_back("Moe");   // Move Constructor
    stooges_vec.push_back("Curly");     // Move Constructor
    
    cout << "==== Loop 1 ======================" << endl;
    for (const Mystring &s : stooges_vec)
        s.display();
        
    cout << "==== Loop 2 =======================" << endl;
    for (Mystring &s : stooges_vec)
        s = "Changed";               // Move assignment
        
        
    for (const Mystring &s : stooges_vec)
        s.display();
     
    
    
    return 0;
} 