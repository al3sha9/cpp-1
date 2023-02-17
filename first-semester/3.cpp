#include <iostream>
using namespace std;

int main()
{
    int marks;
    cout << "ENTER YOUR MARKS\n";
    cin >> marks;

    if (marks >= 45)
    {
        cout << "SUCCESSFULLY PASSED\n";
    }
    else
    {
        cout << "SUCCESSFULY FAILED :)";
    }

    return 0;
}