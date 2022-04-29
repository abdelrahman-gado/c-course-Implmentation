#include <iostream>
#include <iomanip>
#include <string>

void ruler()
{
    std::cout << "\n12345678901234567890123456789012345678901234567890" << std::endl;
}


int main() 
{
    int num1 {1234};
    double num2 {1234.5678};
    std::string hello {"Hello"};
    
    // Defaults
    std::cout << "\n-- Defaults ---------------------------------" << std::endl;
    ruler();
    std::cout << num1 << num2 << hello << std::endl;
    
    std::cout << "\n -- Defaults - one per line -----------------------------" << std::endl;
    ruler();
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << hello << std::endl;
    
    std::cout << "\n-- width 10 for num 1 ------------------------------------" << std::endl;
    ruler();
    std::cout << std::setw(10) << num1
              << num2
              << hello
              << std::endl;
              
    std::cout << "\n-- width 10 for num1 and num2 ----------------------------------" << std::endl;
    ruler();
    std::cout << std::setw(10) << num1
              << std::setw(10) << num2
              << hello
              << std::endl;
              
    std::cout << "\n-- width 10 for num1 and num2 and hello -------------------------" << std::endl;
    ruler();
    std::cout << std::setw(10) << num1
              << std::setw(10) << num2
              << std::setw(10) << hello
              << std::endl;
              
    std::cout << "\n-- width 10 num1 and num2 and hello left for all setfill to dash ------------" << std::endl;
    ruler();
    std::cout << std::setw(10) << std::left << num1
              << std::setw(10) << std::left << num2
              << std::setw(10) << std::left << hello
              << std::endl;
    
    std::cout << "\n-- width 10 for num1 and num2 and hello left for all setfill to dash ------------------" << std::endl;
    std::cout << std::setfill('-');
    ruler();
    std::cout << std::setw(10) << std::left << num1
              << std::setw(10) << std::left << num2
              << std::setw(10) << std::left << hello
              << std::endl;
    
    std::cout << "\n-- width 10 for num1 and num2 and hello - setfill varies ------------------" << std::endl;
    ruler();
    std::cout << std::setw(10) << std::left << std::setfill('*') << num1
              << std::setw(10) << std::left << std::setfill('#') << num2
              << std::setw(10) << std::left << std::setfill('-') << hello
              << std::endl;
    
    
    return 0;
}