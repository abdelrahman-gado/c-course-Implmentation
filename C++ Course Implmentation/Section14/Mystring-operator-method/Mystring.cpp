#include "Mystring.h"
#include <cstring>
#include <cctype>
#include <iostream>

// no-args Constructor
Mystring::Mystring ()
    : str {nullptr}
{
    str = new char[1];
    *str = '\0';
}

// overloaded constructor
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

// Copy Constructor (Deep copy)
Mystring::Mystring (const Mystring &source)
{   
    std::cout << "Using Copy Constructor" << std::endl;
    str = new char [std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
}

// Move Constructor
Mystring::Mystring (Mystring &&source) noexcept
    : str {source.str}
{
    std::cout << "Using Move Constructor" << std::endl;
    source.str = nullptr;
}

// Copy Assignment (Deep Copy Assignment)
Mystring &Mystring::operator= (const Mystring &rhs)
{
    std::cout << "Copy Assignment operator" << std::endl;
    if (this == &rhs)
        return *this;
    
    delete [] str;
    str = new char [std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);
    return *this;
}

// Move Adssignment Operator
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

// Overload negate operator -
Mystring Mystring::operator- () const
{
    char *buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, str);
    for (size_t i {0}; i < std::strlen(buff); i++)
    {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

// Overload == opertaor (Equality)
bool Mystring::operator== (const Mystring &rhs) const
{
    return (std::strcmp(str, rhs.str) == 0);
}

// Overload + operator (concatenation)
Mystring Mystring::operator+ (const Mystring &rhs) const
{
    int buff_size = std::strlen(str) + std::strlen(rhs.str) + 1;
    char *buff = new char [buff_size];
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

Mystring::~Mystring() 
{
    if (str == nullptr)
        std::cout << "Calling Destructor for Mystring : nullptr" << std::endl;
    else
        std::cout << "Calling destructor for Mystring " << str << std::endl;
}


void Mystring::display () const
{
    std::cout << str << " : " << get_length() << std::endl;
}

int Mystring::get_length () const 
{
    return std::strlen(str);
}

const char *Mystring::get_str () const
{
    return str;
}






