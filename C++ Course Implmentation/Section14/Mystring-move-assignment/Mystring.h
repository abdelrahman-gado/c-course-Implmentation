#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
private:
    
    char *str;
    
public:
    
    Mystring ();
    Mystring (const char *s);
    Mystring (const Mystring &source);
    Mystring (Mystring &&source) noexcept;
    
    Mystring &operator= (const Mystring &rhs);
    
    Mystring &operator= (Mystring &&rhs);
    
    
    ~Mystring ();
    
    void display () const;
    int get_length () const;
    const char *get_str () const;

};

#endif // _MYSTRING_H_
