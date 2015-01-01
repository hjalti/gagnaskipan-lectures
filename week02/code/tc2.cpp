#include <iostream>

using namespace std;

int main()
{

    int n;
    cin >> n;
    int x = 0;

    for(int i = 0; i != n; i++)
    {
        x = (x + n) % 5;
    }

    cout << x << endl;

    return 0;
}
