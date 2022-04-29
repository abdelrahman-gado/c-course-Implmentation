#include "Mystring.h"
#include <cstring>
#include <cctype>


Mystring::Mystring ()
    : str {nullptr}
{
     str = new char [1];
     *str = '\0';
}

Mystring::Mystring (const char *s)
    : str {nullptr}
{
    if (s == nullptr)
    {
        str = new char [1];
        *str = '\0';
    }
    else
    {
        str = new char [std::strlen(s) + 1];
        std::strcpy(str, s);
    }
}

Mystring::Mystring (const Mystring &source)
{
    std::cout << "Using the Copy Constructor (Deep Copy)" << std::endl;
    str = new char [std::strlen(source.str) + 1];
    std::strcpy (str, source.str);
}

Mystring::Mystring (Mystring &&source) noexcept
    : str {source.str}
{
    std::cout << "Using the Move Constructor" << std::endl;
    source.str = nullptr;
}

Mystring::~Mystring ()
{
    if (str == nullptr)
        std::cout << "Calling Destructor for Mystring : nullptr" << std::endl;
    else
        std::cout << "Calling Destructor for Mystring : " << str << std::endl;
}

Mystring &Mystring::operator= (const Mystring &rhs)
{
    std::cout << "Copy Assignment operator" << std::endl;
    if (this == &rhs)
        return *this;
        
    delete [] str;
    str = new char [std::strlen(rhs.str) + 1];
    std::strcpy (str, rhs.str);
    return *this;
}

Mystring &Mystring::operator= (Mystring &&rhs)
{
    std::cout << "Move Assignemt operator" << std::endl;
    if (this == &rhs)
        return *this;
    
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
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

// Overload the insertion operator
std::ostream &operator<< (std::ostream &os, const Mystring &rhs)
{
    os << rhs.str;
    return os;
}

// Overload the exraction operator
std::istream &operator>> (std::istream &in, Mystring &rhs)
{
    char *buff = new char [1000];
    in >> buff;
    rhs = Mystring {buff};
    delete [] buff;
    return in;
}

