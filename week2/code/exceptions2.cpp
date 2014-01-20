#include <iostream>

using namespace std;

class NonPrintableException { };

bool is_digit(char c)
{
    if(c < 31)
    {
        throw NonPrintableException();
    }
    return '0' <= c && c <= '9';
}

int main()
{
    char str[] = "Hello 1337";
    for(int i = 0; i != 11; i++)
    {
        cout << "Is '" << str[i] << "' a digit?" << endl;
        cout << is_digit(str[i]) << endl;
    }

    return 0;
}
