#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
private:
    char *str;
    
public:
    Mystring ();                   // no-args constructor
    Mystring (const char *s);   // overloaded constructor
    
    ~Mystring (); // Destructor

    Mystring (const Mystring &source);  // copy constructor (deep copy)
    Mystring (Mystring &&rhs) noexcept;          // move constructor
    
    Mystring &operator= (const Mystring &rhs);  // copy assignement (deep copy assignment)
    Mystring &operator= (Mystring &&rhs);       // move assignment 
    
    Mystring operator- () const;
    bool operator== (const Mystring &rhs) const;
    Mystring operator+ (const Mystring &rhs) const;
    
    
    
    void display () const;
    int get_length() const;
    const char *get_str() const;

};

#endif // _MYSTRING_H_
