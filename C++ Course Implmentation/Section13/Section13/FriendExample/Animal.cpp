#include "Animal.h"

//void Animal::display_friend_animal(Person &p)
//{
//    std::cout << p.name << std::endl;
//    std::cout << p.health << std::endl;
//    std::cout << p.happiness << std::endl;
//}

// constructor
Animal::Animal (std::string name_val, int health_val, int happiness_val)
    : animal_name {name_val}, animal_health {health_val}, animal_happiness {happiness_val}
{
    
}

// copy constructor
Animal::Animal (const Animal &source)
    : Animal {source.animal_name, source.animal_health, source.animal_happiness}
{
    
}


Animal::~Animal ()
{
    
}


