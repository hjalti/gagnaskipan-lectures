#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;

    int n;

    for(int i = 0; i != 10; i++)
    {
        v.push_back(i * 3);
    }

    while(true)
    {
        cin >> n;

        try
        {
            cout << "Checking index with at" << endl;
            cout << "v[" << n << "] = " << v.at(n) << endl;
        }
        catch(out_of_range)
        {
            cout << "Caught out_of_range" << endl;
        }

        cout << "Checking index with operator[]" << endl;
        cout << "v[" << n << "] = " << v[n] << endl;

    }

    return 0;
}
