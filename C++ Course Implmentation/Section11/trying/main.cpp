#include <iostream>

using namespace std;

int add_numbers();
double add_numbers();

int main() 
{
    
    cout << "The sum of 1 and 2 is: " << add_numbers(1, 2) << endl;
    cout << "The sum of 2.6 and 3.1 is: " << add_numbers(2.6, 3.1) << endl;
    
    return 0;
}


int add_numbers()
{
    return 1+2;
}

double add_numbers()
{
    return 2.6+3.1;
}