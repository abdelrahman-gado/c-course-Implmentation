#include <iostream>

using namespace std;

int main() 
{
//    const double usd_per_eur {1.19};
    
//    cout << "Welcome to EUR to USD converter" << endl;
//    cout << "Enter the value in EUR: ";
//    double euros {0.0};
//    double dollars {0.0};
//    cin >> euros;
//    dollars = euros * usd_per_eur;
//    cout << euros << " euros is equivalent to " << dollars << " dollars" << endl;
    
    
    // kilometer to meter converter
    const int kilo_to_meter {1000};
    cout << "Welcome to kilometre to meter converter" << endl;
    cout << "Enter the value in Kilometer: ";
    double kilo_meters {0.0};
    cin >> kilo_meters;
    double meters {0.0};
    meters = kilo_meters * kilo_to_meter;
    cout << kilo_meters << " kilometers is equivalent to " << meters << " meters" << endl;
    
    
    return 0;
}