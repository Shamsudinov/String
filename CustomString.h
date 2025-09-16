#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>

class CustomString{

    int _size;
    int _capacity;
    char *_data;
public:
    explicit CustomString();
    explicit CustomString(char*,int);
    explicit CustomString(const CustomString&);
    ~CustomString();

    int size() const;
    int capacity() const;

    char& operator [](int);
    CustomString operator+(const CustomString&);
    CustomString& operator=(const CustomString&);
    CustomString& operator=(const char*);

    char at(int) const;

    void print() const;

    char* data() const;
};

std::ostream& operator<<(std::ostream&,const CustomString&);

#endif // STRING_H
