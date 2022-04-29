#include <cstring>
#include <iostream>
#include "Mystring.h"

Mystring::Mystring ()
    : str {nullptr}
{
    str = new char[1];
    *str = '\0';
}

Mystring::Mystring (const char *s)
    : str {nullptr}
{
    if (s == nullptr)
    {
        str = new char[1];
        *str = '\0';
    }
    else
    {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
    }
}

// Copy Constructor
Mystring::Mystring (const Mystring &source)
{
    std::cout << "Copy Constructor used" << std::endl;
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
}

// Move Constructor
Mystring::Mystring (Mystring &&source) noexcept
    : str {source.str}
{
    std::cout << "Move Constructor used" << std::endl;
    source.str = nullptr;
}

// Copy Assignmrnt Operator
Mystring &Mystring::operator= (const Mystring &rhs)
{
    std::cout << "Copy assignment operator" << std::endl;
    if (this == &rhs)
        return *this;
    
    delete [] this->str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(this->str, rhs.str);
    return *this;
}

// Move Assignemet Operator
Mystring &Mystring::operator= (Mystring &&rhs)
{
    std::cout << "Move assignment operator" << std::endl;
    
    if (this == &rhs)
        return *this;
        
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    
    return *this;
}


Mystring::~Mystring ()
{
    if (str == nullptr)
    {
        std::cout << "Calling destructor for Mystring : nullptr" << std::endl;
    }
    else
    {
        std::cout << "Calling destructor for Mystring : " << str << std::endl;
    }
}

void Mystring::display() const
{
    std::cout << str << " : " << get_length() << std::endl;
}

int Mystring::get_length() const
{
    return std::strlen(str);
}

const char *Mystring::get_str () const
{
    return str;
} 

