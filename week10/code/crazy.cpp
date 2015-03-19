#include <iostream>
#include <string>

using namespace std;

template<int n>
int funky() {
    return n * funky<n>();
}

template<>
int funky<1>() {
    return 1;
}

template<int n>
int mystery() {
    return mystery<n-1>() + mystery<n-2>();
}

template<>
int mystery<0>() {
    return 0;
}

template<>
int mystery<1>() {
    return 1;
}

int main()
{
    cout << funky<5>() << endl;
    cout << mystery<1>() << endl;
    cout << mystery<2>() << endl;
    cout << mystery<3>() << endl;
    cout << mystery<4>() << endl;
    cout << mystery<5>() << endl;
    cout << mystery<6>() << endl;
    cout << mystery<7>() << endl;
    cout << mystery<8>() << endl;
    cout << mystery<9>() << endl;
    cout << mystery<10>() << endl;

    return 0;
}
