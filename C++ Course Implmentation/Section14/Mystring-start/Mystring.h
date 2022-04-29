#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
private:
    char *str; // pointer to char[] that holds a C-sytle string.
    
public:
    Mystring();   // No-args cosntructor
    Mystring(const char *s);  // Overloaded constructor
    Mystring(const Mystring &source); // copy constrcutor
    ~Mystring();            // Destructor
    
    void display() const;             // getters
    int get_length() const;
    const char *get_str() const;

};

#endif // MYSTRING_H
