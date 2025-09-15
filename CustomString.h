#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>

class CustomString{

    int _size;
    char *data;
public:
    explicit CustomString();
    explicit CustomString(const CustomString&);
    ~CustomString();

    int size() const;
    char& operator [](int);
    CustomString& operator=(const CustomString&);
    CustomString& operator=(const char*);

    char at(int) const;

    void print() const;
};

std::ostream& operator<<(std::ostream&,const CustomString&);

#endif // STRING_H
