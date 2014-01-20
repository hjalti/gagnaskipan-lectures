#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool duplicates(int array[], int length)
{
    for(int i = 0; i < length; i++)
    {
        for(int j = i + 1; j < length; j++)
        {
            if(array[i] == array[j])
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    srand(time(NULL));

    int n;
    cin >> n;

    int *array = new int[n];

    for(int i = 0; i != n; i++)
    {
        array[i] = rand();
    }

    cout << "Searching for duplicates" << endl;
    cout << duplicates(array, n) << endl;

    return 0;
}
