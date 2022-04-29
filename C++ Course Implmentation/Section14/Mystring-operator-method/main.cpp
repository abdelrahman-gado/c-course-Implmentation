#include <iostream>
#include "Mystring.h"


using namespace std;

int main() 
{
    Mystring larry {"LARRY"};
    Mystring moe {"Moe"};
    
    Mystring stooge = larry; // this is not assignment, this is a initalization==== >>> Copy Constructor is called
    
    larry.display();        // LARRY
    moe.display();          // Moe
    
    cout << boolalpha;
    
    cout << (larry == moe) << endl;           // false
    cout << (larry == stooge) << endl;         // true
    
    larry.display();
    Mystring larry2 = -larry; // lowercase
    larry2.display();               // larry
    
    Mystring stooges = larry + "Moe";       // ok with member function
    stooges.display();
    // Mystring stooges2 = "Larry" + moe;       // Compiler Error
    
    Mystring two_stooges = moe + " " + "Larry";  // (moe + " ") ---> object
    two_stooges.display();
    
    Mystring three_stooges = moe + " " + larry + "Curly";
    three_stooges.display();
    
    
    return 0;
}