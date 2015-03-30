#include <iostream>
#include <vector>
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

struct range
{
    range(int start = 0) {
        curr = start;
    }

    int operator () () {
        return curr++;
    }

    int curr;
};

int main()
{
    {
        int x[30];
        generate(x, x+30, range(1));

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
    } {
        vector<int> x(30);
        generate(x.begin(), x.end(), range(1));

        for_each(x.begin(), x.end(), print<int>);
        cout << endl;

        for_each(x.begin(), x.end(), increase_by(10));

        for_each(x.begin(), x.end(), print<int>);
        cout << endl;

        int y[40];
        copy(x.begin(), x.end(), y);

        for_each(y, y+30, print<int>);
        cout << endl;

        cout << equal(x.begin(), x.end(), y) << endl;
    }

    string s1 = "heLLo";
    string s2 = "HELLo";

    cout << equal(s1.begin(), s1.end(), s2.begin()) << endl;
    cout << equal(s1.begin(), s1.end(), s2.begin(), case_insensitive_compare) << endl;
    cout << equal(s1.begin(), s1.end(), s2.begin(), ci_compare()) << endl;

    return 0;
}
