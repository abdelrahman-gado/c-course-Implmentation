#include <iostream>
#include <string>
#include <vector>

using namespace std;

// by pointers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// by reference
/*
 * 
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
 * 
*/

int main() 
{
    int x {100}, y {200};
    cout << "\nx: " << x << endl;
    cout << "y: " << y << endl;
    
    swap(&x, &y);// by pointers
    // swap(x, y); // by reference
    
    cout << "\nx: " << x << endl;
    cout << "y: " << y << endl;
    
    cout << endl;
    return 0;
}