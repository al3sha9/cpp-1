#include <iostream>
using namespace std;

class ShallowCopy
{
private:
    int ptrFirst;
    int *ptr;

public:
    ShallowCopy(int &copy, int copy2)
    {
        ptrFirst = copy2;
        ptr = &copy;
    }
    void display()
    {
        cout << "\nThe Details are:" << endl;
        cout << "\t\tValue of first number is: " << ptrFirst;
        cout << "\n\t\tValue of Second Number is: " << ptrFirst;
        cout << "\n\t\tAddress of the NUMBER is: " << ptr << endl;
        cout << "_____________________________________________________\n";
    }
};

int main()
{
    // variable creation
    int num1 = 6;
    int num2 = 4;

    // object making
    ShallowCopy one(num1, num2);
    ShallowCopy two = one;

    // displaying outputs
    one.display();
    two.display();

    // End of program
    return 0;
}
