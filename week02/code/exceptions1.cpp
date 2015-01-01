#include <iostream>

using namespace std;

class ValueTooLowException { };
class ValueTooHighException { };

int check(int x)
{
    if(x < 4)
    {
        throw ValueTooLowException();
    }
    if(x > 4)
    {
        throw ValueTooHighException();
    }
}

int main()
{
    int n;
    cin >> n;
    try
    {
        check(n);
    }
    catch(ValueTooLowException)
    {
        cout << "Caught ValueTooLowException" << endl;
    }
    catch(ValueTooHighException)
    {
        cout << "Caught ValueTooHighException" << endl;
    }

    return 0;
}
