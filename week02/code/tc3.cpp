#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int find(int n, int array[], int length)
{
    for(int i = 0; i != length; i++)
    {
        if(array[i] == n)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    srand(time(NULL));

    int n;
    cin >> n;

    int *array = new int[n];

    for(int i = 0; i != n; i++)
    {
        array[i] = rand() % n;
    }

    int s = rand() % n;

    cout << "Searching for " << s << endl;
    cout << find(s, array, n) << endl;

    cout << "Searching for -1" << endl;
    cout << find(-1, array, n) << endl;


    return 0;
}
