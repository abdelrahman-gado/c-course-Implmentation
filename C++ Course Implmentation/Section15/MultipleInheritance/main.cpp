#include <iostream>
#include <string>

using namespace std;

class Person 
{
protected:
    string name;
    int age;
    
public:
    Person() : name {""}, age {0} { }
    Person(string name, int age) : name {name}, age {age} { }
    void printPerson() const { cout << "Person name: " << name << ", Person age: " << age << endl; }
    
};


class Employee
{
protected:
    string role;
    double salary;
    
public:
    Employee (string role, double salary) : role {role}, salary {salary} { }
    Employee () : Employee {"No Role", 0.0} { }
    void printEmployee () const { cout << "Employee role: " << role << ", Employee salary: " << salary << endl; }
    
};

class Teacher : public Person, public Employee
{
private:
    string subject;
    
public:
    Teacher (string name, int age, string role, double salary, string subject)
        : Person(name, age), Employee(role, salary), subject {subject}
    {
        
    }
    
    Teacher () : Person(), Employee(), subject {"No Subject"}
    {
        
    }
    
    void printTeacher() const 
    {
        Person::printPerson();
        Employee::printEmployee();
        cout << "subject: " << subject << endl;
    }

};


int main() 
{
    Teacher t {"Abdo", 23, "head Teacher", 5000.0, "English"};
    t.printTeacher();
    
    return 0;
}