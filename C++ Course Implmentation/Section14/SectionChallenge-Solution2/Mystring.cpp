#include "Mystring.h"
#include <cstring>
#include <cctype>

// no-args constructor
Mystring::Mystring ()
    : str {nullptr}
{
    //std::cout << "No-args Constructor called" << std::endl; 
    str = new char [1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring (const char *s)
{
    //std::cout << "Overloaded Constructor called" << std::endl;
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


// Copy constructor
Mystring::Mystring (const Mystring &source)
{
    //std::cout << "Copy Constructor called" << std::endl;
    str = new char [std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
}

// Move Constructor
Mystring::Mystring (Mystring &&source) noexcept
    : str {source.str}
{
    //std::cout << "Move Constructor called" << std::endl;
    source.str = nullptr;
}

// Copy assignment (Deep Copy)
Mystring &Mystring::operator= (const Mystring &rhs)
{
    //std::cout << "Copy Assignment called" << std::endl;
    if (this == &rhs)
        return *this;
    
    delete [] str;
    str = new char [std::strlen(rhs.str) + 1];
    std::strcpy (str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator= (Mystring &&rhs)
{
    //std::cout << "Move Assignment called" << std::endl;
    if (this == &rhs)
        return *this;
    
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

// Overload - operator (make lowercase)
Mystring operator- (const Mystring &obj)
{
    char *buff = new char[std::strlen(obj.str) + 1];
    std::strcpy(buff, obj.str);
    for (size_t i {0}; i < std::strlen(buff); i++)
    {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

// Overload == operator
bool operator== (const Mystring &lhs, const Mystring &rhs)
{
    return (std::strcmp(lhs.str, rhs.str) == 0);
}

// Overload != operator
bool operator!= (const Mystring &lhs, const Mystring &rhs)
{
    return (!std::strcmp(lhs.str, rhs.str) == 0);
}

// Overload < operator
bool operator< (const Mystring &lhs, const Mystring &rhs)
{
    return (std::strcmp(lhs.str, rhs.str) < 0);
}

// Overload > operator
bool operator> (const Mystring &lhs, const Mystring &rhs)
{
    return (std::strcmp(lhs.str, rhs.str) > 0);
}


// Overload + operator
Mystring operator+ (const Mystring &lhs, const Mystring &rhs)
{
    int buff_size = std::strlen(lhs.str) + std::strlen(rhs.str) + 1;
    char *buff = new char [buff_size];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    
    Mystring temp {buff};
    delete [] buff;
    return temp;
}


// Overload += operator
Mystring &operator+= (Mystring &lhs, const Mystring &rhs)
{
    lhs = lhs + rhs;      // operator+ (lhs, rhs);
    return lhs;
}

// Overload * operator
Mystring operator* (const Mystring &lhs, int times)
{
    Mystring temp;
    for (int i {0}; i < times; i++)
    {
        temp = temp + lhs; // operator+ (temp, lhs);
    }
    
    return temp;
}

// Overload *= operator
Mystring &operator*= (Mystring &lhs, int times)
{
   lhs = lhs * times;  // operator* (lhs, times);
   return lhs;
}


// Overload ++ opertaor (make Uppercase [pre])
Mystring &operator++ (Mystring &obj)
{
    for (size_t i {0}; i < std::strlen(obj.str); i++)
    {
        obj.str[i] = std::toupper(obj.str[i]);
    }
    
    return obj;
}


// Overload ++ operator (make Uppercase [post])
Mystring operator++ (Mystring &obj, int)
{
    Mystring temp {obj};
    ++obj;
    return temp;
}

// Overload -- operator (make lowercase [pre])
Mystring &operator-- (Mystring &obj)
{
    for (size_t i {0}; i < std::strlen(obj.str); i++)
        obj.str[i] = std::tolower(obj.str[i]);
    
    return obj;
}

// Overload -- operator (make lowercase [post])
Mystring operator-- (Mystring &obj, int)
{
    Mystring temp {obj};
    --obj;
    return obj;
}



Mystring::~Mystring ()
{
    if (str != nullptr)
        std::cout << "Destructor called for Mystring : " << str << std::endl;
        
    
    delete [] str;
}


void Mystring::display() const
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


// Overload << operator
std::ostream &operator<< (std::ostream &os, const Mystring &rhs)
{
    os << rhs.str;
    return os;
}

// Overload >> operator
std::istream &operator>> (std::istream &is, Mystring &rhs)
{
    char *buff = new char [1000];
    is >> buff;
    rhs = Mystring {buff};        // Move assignment 
    delete [] buff;
    return is;
}
