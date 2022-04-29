#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Player
{
    // attributes
    string name {"player"};
    int health {100};
    int xp {3};
    
    // methods
    void talk(string);
    bool is_dead();
};

class Account
{
    // attributes
    string name {"Account"};
    double balance {0.0};
    
    // method
    bool deposit(double);
    bool withdraw(double);
    
};


int main() 
{
    
    
    return 0;
}