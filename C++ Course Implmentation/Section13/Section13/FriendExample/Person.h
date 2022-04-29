#include "Animal.h"
#ifndef PERSON_H
#define PERSON_H


#include <string>

#include <iostream>

class Animal; // forward declaration of Animal because we are making a cycling between Animal and Person

class Person
{
private:
    std::string name;
    int health;
    int happiness;

public:
    
    void set_name (std::string name_val) { name = name_val; }
    std::string get_name () { return name; }
    int get_health () { return health; }
    int get_happiness () { return happiness; }
    void display_animal_friend (Animal &A);
    

    // constructor
    Person(std::string name_val = "None", int health_val = 100, int happiness_val = 50);
    
    // copy constructor
    Person(const Person &source);
    
    // Destructor
    ~Person();
};

#endif // PERSON_H
