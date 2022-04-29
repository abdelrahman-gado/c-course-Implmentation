#include <iostream>

using namespace std;

int main() 
{   
    cout << "Hello, welcome to Frank's Carpet Cleaning Service" << endl;
    
    int num_small_room {0};
    cout << "\nHow many small rooms would you like cleaned? ";
    cin >> num_small_room;
    
    int num_large_room {0};
    cout << "How many large rooms would you like cleaned? ";
    cin >> num_large_room;
    
    cout << endl;
    
    const double PRICE_SMALL_ROOM {25};
    const double PRICE_LARGE_ROOM {35};
    
    const double TAX_RATE {0.06};
    const int ESTIMATE_EXPIRY {30}; // Days
    
    cout << "Estimate for carpet cleaning service" << endl;
    cout << "Number of small rooms: " << num_small_room << endl;
    cout << "Number of large rooms: " << num_large_room << endl;
    
    cout << "Price per small room: $" << PRICE_SMALL_ROOM << endl;
    
    cout << "Price per large room: $" << PRICE_LARGE_ROOM << endl;
    
    double cost {(num_small_room * PRICE_SMALL_ROOM) + (num_large_room * PRICE_LARGE_ROOM)};
    cout << "Cost: $" << cost << endl;
    
    
    double tax {cost * TAX_RATE};
    cout << "Tax: $" << tax << endl;
    
    cout << "====================================================\n";
    
    double total_estimate {cost + tax};

    cout << "Total estimate: $" << total_estimate << endl;
    
    cout << "This estimate is valid for "<< ESTIMATE_EXPIRY << " days" << endl;
    
    
    
    
    return 0;
}