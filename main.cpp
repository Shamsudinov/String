#include <iostream>
#include "CustomString.h"
#include <string>
using namespace std;

int main()
{
    CustomString s;
    s = "Hello World!";
    cout << s;
    s[1] = 'h';
    cout << s;
    return 0;
}
