#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

template<class T>
void print(T t) {
    cout << t << " ";
}

bool case_insensitive_compare(char c1, char c2) {
    return tolower(c1) == tolower(c2);
}

struct ci_compare
{
    bool operator() (char c1, char c2) {
        return tolower(c1) == tolower(c2);
    }
};

struct increase_by
{
    increase_by(int x) {
        this->x = x;
    }

    void operator () (int &n) {
        n += x;
    }
    int x;
};

int main()
{
    int x[30];
    for(int i = 0; i < 30; i++) {
        x[i] = i;
    }

    for_each(x, x+30, print<int>);
    cout << endl;

    for_each(x, x+30, increase_by(10));

    for_each(x, x+30, print<int>);
    cout << endl;

    int y[40];
    copy(x, x+30, y);

    for_each(y, y+30, print<int>);
    cout << endl;

    cout << equal(x, x+30, y) << endl;

    string s1 = "heLLo";
    string s2 = "HELLo";

    cout << equal(s1.begin(), s1.end(), s2.begin()) << endl;
    cout << equal(s1.begin(), s1.end(), s2.begin(), case_insensitive_compare) << endl;
    cout << equal(s1.begin(), s1.end(), s2.begin(), ci_compare()) << endl;

    return 0;
}
