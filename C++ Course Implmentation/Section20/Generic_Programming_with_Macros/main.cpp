#include <iostream>

// #define MAX_SIZE 100
// #define PI 3.14159

// #define MAX(a, b) ((a > b) ? a : b)

#define SQUARE(a) ((a)*(a))

int main() 
{
//    std::cout << MAX(5, 8) << std::endl;
//    std::cout << MAX(2.4, 3.5) << std::endl;
//    std::cout << MAX('A', 'C') << std::endl;

    int result1 = SQUARE(5); // Expect 25
    std::cout << result1 << std::endl;
    
    int result2 = 100 / SQUARE(5); // Expect 4
    std::cout << result2 << std::endl;
    
    return 0;
}