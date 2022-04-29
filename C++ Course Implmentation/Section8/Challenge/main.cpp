#include <iostream>

using namespace std;

int main() 
{
    cout << endl;
    
    cout << "Enter an amount in cents: ";
    int cents {0};
    cin >> cents;
    
    const int dollar {100}, quarter {25}, dime {10}, nickel {5}, penny {1};
    
    int num_dollars = cents / dollar;
    cents %= dollar;
    cout << "dollars : " << num_dollars << endl;
    
    int num_quarters = cents / quarter;
    cents %= quarter;
    cout << "quarter : " << num_quarters << endl;
    
    int num_dimes = cents / dime;
    cents  %= dime;
    cout << "dimes   : " << num_dimes << endl;
    
    int num_nickels = cents / nickel;
    cents %= nickel;
    cout << "nickels : " << num_nickels << endl;
    
    int num_penny = cents / penny;
    cout << "pennies : " << num_penny << endl;
    
    
    
    
    return 0;
}