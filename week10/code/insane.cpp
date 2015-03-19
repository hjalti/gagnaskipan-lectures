#include <iostream>
#include <string>

using namespace std;


template <int n>
struct factorial {
    enum { value = n * factorial<n - 1>::value };
};

template <>
struct factorial<0> {
    enum { value = 1 };
};

template <int n>
struct fibo {
    enum { value = fibo<n - 1>::value + fibo<n - 2>::value };
};

template <>
struct fibo<1> {
    enum { value = 1 };
};

template <>
struct fibo<0> {
    enum { value = 0 };
};

int main()
{
    cout << factorial<1>::value << endl;
    cout << factorial<2>::value << endl;
    cout << factorial<3>::value << endl;
    cout << factorial<4>::value << endl;
    cout << factorial<10>::value << endl;

    cout << fibo<5>::value << endl;
    cout << fibo<41>::value << endl;

    return 0;
}
