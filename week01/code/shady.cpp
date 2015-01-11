#include<iostream>

using namespace std;

int * shady()
{
    int a = 1337;
    return &a;
}

int innocent(int x)
{
    int b = 42;
    return x * b;
}

int main()
{
    int x = 3;
    int &y = x;

    int * b = shady();
    cout << *b << endl;
    innocent(4);
    cout << *b << endl;

	return 0;
}
