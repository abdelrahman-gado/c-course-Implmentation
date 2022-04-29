#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <iostream>

class Mystring
{
    
    friend std::ostream &operator<< (std::ostream &os, const Mystring &rhs);     // Overloading << operator
    friend std::istream &operator>> (std::istream &is, Mystring &rhs);           // Overloading >> operator
    friend Mystring operator- (const Mystring &obj);                             // Overload - operator (make lowercase)
    friend bool operator== (const Mystring &lhs, const Mystring &rhs);           // Overload == operator
    friend bool operator!= (const Mystring &lhs, const Mystring &rhs);           // Overload != operator
    friend bool operator< (const Mystring &lhs, const Mystring &rhs);           // Overload < operator
    friend bool operator> (const Mystring &lhs, const Mystring &rhs);           // Overload > operator
    friend Mystring operator+ (const Mystring &lhs, const Mystring &rhs);       // Overload + operator
    friend Mystring &operator+= (Mystring &lhs, const Mystring &rhs);           // Overload += operator
    friend Mystring operator* (const Mystring &lhs, int times);                 // Overload * operator
    friend Mystring &operator*= (Mystring &lhs, int times);                     // Overload *= operator
    friend Mystring &operator++ (Mystring &obj);                                // Overload ++ operator (make Uppercase) [pre]
    friend Mystring operator++ (Mystring &obj, int);                            // Overload ++ operator (make Uppercase) [post]
    friend Mystring &operator-- (Mystring &obj);                                // Overload -- operator (make lowercase)  [pre]
    friend Mystring operator-- (Mystring &obj, int);                            // Overload -- operator (make lowercase)  [post]
    
    
private:
    
    char *str;
    
public:
    
    Mystring ();                        // no-args Constructor
    Mystring (const char *s);           // Overloaded Constructor
    Mystring (const Mystring &source);  // Copy Constructor (Deep Copy)
    Mystring (Mystring &&source) noexcept;       // Move Constructor
    ~Mystring ();                                // Destructor
    
    Mystring &operator= (const Mystring &rhs);    // Copy Assignment operator (Deep Copy)
    Mystring &operator= (Mystring &&rhs);         // Move Assignment operator
    
    
    void display () const;
    int get_length() const;
    const char *get_str() const;

};



#endif // _Mystring_H_
