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

// overload - operator (make lowercase)
Mystring Mystring::operator- () const
{
    char *buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, str);
    for (size_t i {0}; i < std::strlen(buff); i++)
        buff[i] = std::tolower(buff[i]);
    
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

// Overload operator ==
bool Mystring::operator== (const Mystring &rhs) const
{
    return (std::strcmp(str, rhs.str) == 0);
}

// Overload operator !=clTabCtrl
bool Mystring::operator!= (const Mystring &rhs) const
{
    return (std::strcmp(str, rhs.str) != 0);
}

// Overload operator <
bool Mystring::operator< (const Mystring &rhs) const
{
    if (str < rhs.str)
        return true;
    else
        return false;
}

// Overload operator >
bool Mystring::operator> (const Mystring &rhs) const
{
    if (str > rhs.str)
        return true;
    else
        return false;
}


// Overlaod + operator (Concatenation)
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


// Overload += operator
Mystring &Mystring::operator+= (const Mystring &rhs)
{
    *this = *this + rhs;
    return *this;
}

// Overload * operator (repeat)
Mystring Mystring::operator* (int times) const
{
    Mystring temp;
    for (int i {}; i < times; i++)
    {
        temp = temp + *this;
    }
    return temp;
}

// Overload *= operator
Mystring &Mystring::operator*= (int times)
{
    *this = *this * times;
    return *this;
}

// Overload ++ operator (pre-increment)
Mystring &Mystring::operator++ ()
{
    for (int i {}; i < get_length(); i++)
    {
        str[i] = std::toupper(str[i]);
    }
    
    return *this;
}

// Overload ++ operator (post-increment)
Mystring Mystring::operator++ (int)
{
    Mystring temp {*this};        // copy constructor is called
    operator++ ();
    return temp;
}


// Overload -- operator (pre-deceremnet) make lowercase
Mystring &Mystring::operator-- ()
{
    for (int i {0}; i < get_length(); i++)
        str[i] = std::tolower(str[i]);
    
    return *this;
}


// Overload -- operator (post-decrement) make lowercase
Mystring Mystring::operator-- (int)
{
    // can't make a reference to a local variable to that operator and return it.
    Mystring temp {*this};
    operator --();
    return temp;
}



// Destructor
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




