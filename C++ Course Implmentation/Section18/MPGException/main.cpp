#include <iostream>

using namespace std;

int main() 
{
    
    int miles {};
    int gallons {};
    double miles_per_gallon {};
    
    cout << "Enter the miles driven: ";
    cin >> miles;
    cout << "Enter the gallons used: ";
    cin >> gallons;
    
    try
    {
        if (gallons == 0)
            throw 0;
        miles_per_gallon = static_cast<double>(miles) / gallons;
        std::cout << "Result: " << miles_per_gallon << std::endl;
    }
    catch(int &ex)
    {
        std::cerr << "Sorry, can't divide by zero" << std::endl;
    }
    
    std::cout << "Bye" << std::endl; 
    
    return 0;
}