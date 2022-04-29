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

// deep copy
Mystring::Mystring (const Mystring &source)
    : str {nullptr}
{
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
}

// overload assignment operator {copy assignment} (deep copy)
Mystring &Mystring::operator= (const Mystring &rhs)
{
    if (this == &rhs)  // check self assignment
        return *this;
        
    delete [] this->str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(this->str, rhs.str);
    return *this;
}




Mystring::~Mystring ()
{
    delete [] str;
}

void Mystring::display () const
{
    std::cout << str << " : " << get_length() << std::endl;
}

int Mystring::get_length() const
{
    return std::strlen(str);
}

const char *Mystring::get_str() const
{
    return str;
}