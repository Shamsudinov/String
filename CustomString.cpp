#include "CustomString.h"

CustomString::CustomString () :
    _size(0),
    _capacity(MIN_CAPACITY),
    _data(new (std::nothrow) char[_capacity]){

    if(_data != nullptr){
        std::cout << "CustomString();" << std::endl;
    } else {
        std::cout << "Memory allocation error" << std::endl;
    }
}

CustomString::CustomString(char* data, int size){

    _size = size;
    _capacity = MIN_CAPACITY;
    if(_size >= _capacity){
        _capacity = _size + _capacity;
    }

    _data = new (std::nothrow) char[_capacity];
    if(_data != nullptr){
        std::cout << "CustomString(char* data, int size)" << std::endl;
        std::strcpy(_data,data);
        _data[_size] = '\0';
    } else {
        std::cout << "Memory allocation error" << std::endl;
    }
}

CustomString::CustomString(const CustomString& str){

    _capacity = str.capacity();
    _size = str.size();
    _data = new (std::nothrow) char[_capacity];
    if(_data != nullptr){
        for(int idx = 0; idx < _size; idx++){
            _data[idx] = str.at(idx);
        }
        _data[_size] = '\0';
    } else {
         std::cout << "CustomString(const CustomString& str)" << std::endl;
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

    char *new_data = new char[_capacity + str.capacity()];
    std::strcpy(new_data,_data);
    std::strcat(new_data,str.data());
    CustomString result_string(new_data,_size + str.size());
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

    delete [] _data;
    _size = strlen(str);
    if(_size >= _capacity)
        _capacity = _size + MIN_CAPACITY;
    _data = new (std::nothrow) char[_capacity];
    if(_data != nullptr){
        std::cout << "operator=(const char *str)" << std::endl;
        for(int idx = 0; idx < _size; idx++) {
            _data[idx] = str[idx];
        }
        _data[_size] = '\0';
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

    if(_size == 0)
        return true;
    return false;
}

std::ostream& operator<<(std::ostream &os, const CustomString &str)
{
    str.print();
    return os;
}
