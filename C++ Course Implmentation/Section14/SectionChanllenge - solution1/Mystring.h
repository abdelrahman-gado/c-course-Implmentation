#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <iostream>

class Mystring
{
    
    friend std::ostream &operator<< (std::ostream &os, const Mystring &rhs);     // Overloading << operator
    friend std::istream &operator>> (std::istream &is, Mystring &rhs);           // Overloading >> operator
    
    
private:
    
    char *str;
    
public:
    
    Mystring ();                        // no-args Constructor
    Mystring (const char *s);           // Overloaded Constructor
    Mystring (const Mystring &source);  // Copy Constructor (Deep Copy)
    Mystring (Mystring &&source) noexcept;       // Move Constructor
    ~Mystring ();                                // Destructor
    
    Mystring &operator= (const Mystring &rhs);   // Copy Assignment (Deep Copy)
    Mystring &operator= (Mystring &&rhs);        // Move assignment
    
    Mystring operator- () const;                     // - operator (make lowercase)
    Mystring operator+ (const Mystring &rhs) const;  // overlaod operator + (concatenation)
    Mystring operator* (int times) const;            // Overload operator * (repeat)
    
    Mystring &operator+= (const Mystring &rhs);      // Overload operator += 
    Mystring &operator*= (int times);                // Overload operator *=
    
    Mystring &operator++ ();                       // Overload operator ++ (pre-increment)  make uppercase
    Mystring operator++ (int);                     // Overload operator ++ (post-increment) make uppercase
    
    Mystring &operator-- ();                       // Overload operator -- (pre-decrement) make lowercase
    Mystring operator-- (int);                    // Overload operator -- (post-decrement) make lowercase
    
    
    
    
    
    
    bool operator== (const Mystring &rhs) const;    // overload operator == 
    bool operator!= (const Mystring &rhs) const;    // Overload operator !=
    bool operator< (const Mystring &rhs) const;     // overload operator <
    bool operator> (const Mystring &rhs) const;     // overload operator >
    
    
    
    
    
    
    
    void display () const;
    int get_length() const;
    const char *get_str() const;

};

#endif // _MYSTRING_H_
