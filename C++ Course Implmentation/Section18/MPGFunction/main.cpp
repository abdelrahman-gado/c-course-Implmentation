#include <iostream>

using namespace std;

double calculate_avg(int miles, int gallons)
{
    if (gallons == 0)
        throw 0;
    return static_cast<double>(miles) / gallons;
}


int main() 
{
    int miles {};
    int gallons {};
    double miles_per_gallon {};
    
    std::cout << "Enter the miles: ";
    std::cin >> miles;
    std::cout << "Enter the gallons: ";
    std::cin >> gallons;
    
    try
    {
        miles_per_gallon = calculate_avg(miles, gallons);
        std::cout << "Result: " << miles_per_gallon << std::endl;
    }
    catch (int &ex)
    {
        std::cerr << "Tried to divide" << std::endl;
    }
    std::cout << "Bye" << std::endl;
    
    
    return 0;
}