#include <iostream>


using namespace std;

/*
 * 
 * increment and decrement operator
 * don't use it twice in the same variable and i the same statment.
 * 
 * 
 *    */

int main() 
{
    int counter {10};
    int result {0};
//    
//    // Example 1
//    cout << "Counter: " << counter << endl;
//    
//    counter = counter + 1;
//    cout << "Counter: " << counter << endl;
//    
//    counter++;
//    cout << "Counter: " << counter << endl;
//    
//    ++counter;
//    cout << "Counter: " << counter << endl;
//    

//     Example 2
//    counter = 10;
//    result = 0;
//    
//    cout << "Counter: " << counter << endl;
//    
//    result = ++counter;  pre-increment
//    cout << "Counter: " << counter << endl;
//    cout << "Result: " << result << endl; 
    
    // Example 3
//    counter = 10;
//    result = 0;
//    
//    cout << "Counetr: " << counter << endl;
//    
//    result = counter++; // post-increment
//    cout << "Counter: " << counter << endl;
//    cout << "Result: " << result << endl;

    // Example 4
//    counter = 10;
//    result = 0;
//    
//    cout << "Counter: " << counter << endl;
//    result = ++counter + 10; // pre-increment
//    
//    cout << "Counter: " << counter << endl;
//    cout << "Result: " << result << endl;

     // Example 5
     
    counter = 10;
    result = 0;
    
    cout << "Counter: " << counter << endl;
    
    result = counter++ + 10; // post-increment
    // counter = counter + 10;
    // counter = counter + 1;
    cout << "Counter: " << counter << endl;
    cout << "Result: " << result << endl;
     
    return 0;
}