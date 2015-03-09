#include <iostream>

using namespace std;

class A
{
    public:
        A() {
            x = 42;
        }
        void f() {
            cout << "x: " << x << endl;
        }

    private:
        int x;
};

class B : public A {
    public:
        void g() {
            cout << "I'm an instance of B" << endl;
        }
};

int main()
{
    A a;
    a.f();

    B b;
    b.f();
    b.g();
    return 0;
}
