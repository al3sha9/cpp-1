#include <iostream>
using namespace std;

template <class T>

class Calculator
{
private:
    T num1, num2;

public:
    Calculator(T n1, T n2)
    {
        num1 = n1;
        num2 = n2;
    }
    T add()
    {
        if (num2 != 0)
        {
            return (num1 / num2);
        }
        else
        {
            throw runtime_error("Error: Division by zero");
        }
    }

    void dis()
    {
        try
        {
            cout << "Result of dividing num1 by num2 is: " << add() << endl;
        }
        catch (const exception &e)
        {
            cerr << e.what() << endl;
        }
    }
};
int main()
{
    Calculator<float> obj1(34.55, 89.44);
    Calculator<int> obj2(34, 0);
    obj1.dis();
    obj2.dis();
    return 0;
}