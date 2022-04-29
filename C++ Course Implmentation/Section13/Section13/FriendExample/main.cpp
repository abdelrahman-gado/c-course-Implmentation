#include <iostream>
#include "Person.h"
#include "Animal.h"

using namespace std;

//void display_person (Person &p)
//{
//    // This friend function can change the private attributes.
//    // p.name = "abdou";
//    cout << p.get_name() << endl;
//    cout << p.get_health() << endl;
//    cout << p.get_happiness() << endl;
//}

int main() 
{
    Animal doggy {"doggy", 100, 80};
    Person frank {"frank", 99, 70};
    
    frank.display_animal_friend (doggy);
    //doggy.display_friend_animal(frank);
    //display_person (frank);
    return 0;
}