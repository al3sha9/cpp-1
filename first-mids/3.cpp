#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "ENTER NUMBER A\n";
    cin >> a;
    cout << "ENTER NUMBER B\n";
    cin >> b;

    if (a >= b)
    {
        cout << "NUMBER A IS GREATER\n";
    }
    else
    {
        cout << "NUMBER B IS GREATER";
    }

    return 0;
}