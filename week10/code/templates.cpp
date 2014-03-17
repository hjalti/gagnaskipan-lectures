#include <iostream>
#include <string>

template<class T>
void swap(T& t1, T& t2) {
    T tmp = t2;
    t2 = t1;
    t1 = tmp;
}

template<class T>
void print(T t) {
    std::cout << t << std::endl;
}

int main()
{
    print(1327);
    print("asdf");

    int x = 1337, y = 42;
    double a = 'x', b = 'y';
    std::string s = "lo", t = "yo";

    swap(x,y);
    print(x);
    print(y);
    swap(a,b);
    print<char>(a);
    print(b);
    swap(s,t);
    print(s);
    print(t);
    return 0;
}
