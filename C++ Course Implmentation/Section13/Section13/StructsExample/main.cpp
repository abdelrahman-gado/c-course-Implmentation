#include <iostream>
#include <string>

using namespace std;

struct Person
{
    // all data members and methods are public by default
    std::string name {"none"};
    int health;
    //std::string get_name(); // this is not a best practice
};

//std::string Person::get_name()
//{
//    return name;
//}


int main() 
{
    Person frank {"Frank", 100};
    cout << frank.get_name() << endl;
    return 0;
}