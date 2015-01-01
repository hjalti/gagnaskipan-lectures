#include <iostream>

using namespace std;

int odd(int n)
{
    return n % 2 == 1;
}

int main()
{
    int n;
    cin >> n;

    odd(n);

    return 0;
}
