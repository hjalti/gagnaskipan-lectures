#include <iostream>
#include <string>

using namespace std;

class A {
    public:
        string s;
        A(string s) {
            this->s = s;
        }
        A(const A& a) {
            cout << ">>>>> Constructing a copy of A(" << a.s << ")" << endl;
            s = a.s + " (copy)";
        }
        ~A() {
            cout << "##### Calling destructor of A(" << s << ")" << endl;
        }
        void operator=(const A& a) {
            cout << "----- Calling operator= of A(" << s << ")" << endl;
            string olds = s;
            s = a.s + " (used to be " + olds + ")";
        }
};

A stuff2(int a) {
    if(a) {
        cout << "Entering stuff2" << endl;
        A b = A("Inside stuff2");
        cout << "Exiting stuff2" << endl;
        return b;
    }
    return A("WAT");
}

void stuff(A a) {
    cout << "Entering stuff" << endl;
    A b = A("Inside stuff");
    cout << "Exiting stuff" << endl;
}

int main() {
    cout << "Entering main" << endl;
    A a = A("In main");

    cout << "Before calling stuff" << endl;
    stuff(a);
    cout << "After calling stuff" << endl;


    A b = A("Another in new");


    cout << "Assigning a to b" << endl;
    b = a;

    cout << "Before calling stuff2" << endl;
    A c = stuff2(true);
    // A c("c");
    // c = stuff2();
    cout << "After calling stuff2" << endl;

    cout << "Exiting main" << endl;
}
