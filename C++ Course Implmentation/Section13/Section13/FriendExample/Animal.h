#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include "Person.h"

class Animal
{
private:
    
    friend class Person;
    std::string animal_name;
    int animal_health;
    int animal_happiness;

public:
    
    void set_animal_name (std::string name) { animal_name = name; }
    std::string get_animal_name () { return animal_name; }
    int get_animal_health () { return animal_health; }
    int get_animal_happiness () { return animal_happiness; }
    
    
    Animal(std::string name_val = "Animy", int health_val = 100, int happiness_val = 50);
    
    Animal(const Animal &source);
    
    ~Animal();
    

};

#endif // ANIMAL_H
