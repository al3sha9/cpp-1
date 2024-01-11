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
        return (num1 + num2);
    }
    void dis()
    {
        cout << "adding num 1 and 2 is: " << add() << endl;
    }
};
int main()
{
    Calculator<float> obj1(34.55, 89.44);
    Calculator<int> obj2(34, 89);
    obj1.dis();
    obj2.dis();
    return 0;
}