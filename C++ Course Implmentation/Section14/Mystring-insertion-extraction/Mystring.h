#ifndef _Mystring_H_
#define _Mystring_H_

#include <iostream>

class Mystring
{
    friend std::ostream &operator<< (std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>> (std::istream &in, Mystring &rhs);
    
private:
    char *str;
    
public:
    Mystring ();
    Mystring (const char *s);
    Mystring (const Mystring &source);
    Mystring (Mystring &&source) noexcept;
    ~Mystring ();
    
    Mystring &operator= (const Mystring &rhs);
    Mystring &operator= (Mystring &&rhs);
    
    void display () const;
    int get_length() const;
    const char *get_str () const;
    
};

#endif // _Mystring_H_
