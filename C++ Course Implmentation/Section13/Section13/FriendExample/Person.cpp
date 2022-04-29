#include "Person.h"
#include "Animal.h"

void Person::display_animal_friend(Animal &A)
{
    std::cout << "My animal friend is " << A.animal_name << std::endl;
    
}


Person::Person (std::string name_val, int health_val, int happiness_val)
    : name {name_val}, health {health_val}, happiness {happiness_val}
{
    
}

// copy-constructor (shallow copy)
Person::Person (const Person &source)
    : Person {source.name, source.health, source.happiness}
{
    
}

// Destructor
Person::~Person ()
{
    
}