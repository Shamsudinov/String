#include "CustomString.h"

CustomString::CustomString (){

    std::cout << "Cstring();" << std::endl;
    _size = 100;
    _data = new char[_size];
}

CustomString::CustomString(char* data, int size){

    _size = size;
    _data = new char[_size];
    std::strcpy(_data,data);
}

CustomString::CustomString(const CustomString& str){

    std::cout << "Cstring() copy;" << std::endl;
    _size = str.size();
    _data = new char[_size];
    for(int idx = 0; idx < _size; idx++){
        _data[idx] = str.at(idx);
    }
}

CustomString::~CustomString(){
    delete [] _data;
}

int CustomString::size() const {
    return _size;
}

int CustomString::capacity() const{
    return _capacity;
}

char& CustomString::operator [](int index){

    std::cout << "operator[](int index)" << std::endl;
    if(index >= _size)
        throw std::out_of_range("CustomString::operator []");
    return _data[index];
}

CustomString CustomString::operator+(const CustomString& str){

    int new_size = _size + str.size();
    char *new_data = new char[new_size];
    std::strcpy(new_data,_data);
    std::strcat(new_data,str.data());
    CustomString result_string(new_data,new_size);
    delete [] new_data;
    return CustomString(result_string);
}

CustomString& CustomString::operator=(const CustomString& str){

    std::cout << "operator=(const CustomString& str)" << std::endl;
    delete [] _data;
    _size = str.size();
    _data = new char[_size];
    for(int idx = 0; idx < _size; idx++){
        _data[idx] = str.at(idx);
    }
    return *this;
}

CustomString& CustomString::operator=(const char *str){

    std::cout << "operator=(const char *str)" << std::endl;
    delete [] _data;
    _size = strlen(str);
    _data = new char[_size];
    for(int idx = 0; idx < _size; idx++) {
        _data[idx] = str[idx];
    }
    return *this;
}

char CustomString::at(int index) const {

    if(index >= _size)
        throw std::out_of_range("CustomString::at(int index) const");
    return _data[index];
}

void CustomString::print() const {

    for(int index = 0; index < _size; index++){
        std::cout<<_data[index];
    }
    std::cout<<std::endl;
}

char *CustomString::data() const {
    return _data;
}

bool CustomString::empty() const{

    if(write_pos == 0)
        return true;
    return false;
}

std::ostream& operator<<(std::ostream &os, const CustomString &str)
{
    str.print();
    return os;
}
