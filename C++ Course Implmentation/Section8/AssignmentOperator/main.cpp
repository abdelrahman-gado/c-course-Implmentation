#include <iostream>

using namespace std;

int main() 
{
    const int num1 {10}; // init
    int num2 {20}; // init
    
    100 = num1;
    
    cout << "num1 is " << num1 << endl;
    cout << "num2 is " << num2 << endl;
    
    cout << endl;
    
    return 0;
}