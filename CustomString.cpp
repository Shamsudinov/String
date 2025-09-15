#include "CustomString.h"

CustomString::CustomString (){

    std::cout << "Cstring();" << std::endl;
    _size = 100;
    data = new char[_size];
}

CustomString::CustomString(const CustomString& str)
{
    std::cout << "Cstring() copy;" << std::endl;
    delete [] data;
    _size = str.size();
    data = new char[_size];
    for(int idx = 0; idx < _size; idx++){
        data[idx] = str.at(idx);
    }
}

CustomString::~CustomString(){
    delete [] data;
}

int CustomString::size() const{
    return _size;
}

char& CustomString::operator [](int index){
    return data[index];
}

CustomString& CustomString::operator=(const CustomString& str){

    delete [] data;
    _size = str.size();
    data = new char[_size];
    for(int idx = 0; idx < _size; idx++){
        data[idx] = str.at(idx);
    }

    return *this;
}

CustomString& CustomString::operator=(const char *str){

    delete [] data;
    _size = strlen(str);
    data = new char[_size];
    for(int idx = 0; idx < _size; idx++){
        data[idx] = str[idx];
    }

    return *this;
}

char CustomString::at(int index) const{
    return data[index];
}

void CustomString::print() const{
    for(int index = 0; index < _size; index++){
        std::cout<<data[index];
    }
    std::cout<<std::endl;
}



std::ostream& operator<<(std::ostream &os, const CustomString &str)
{
    str.print();
    return os;
}
