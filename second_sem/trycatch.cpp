#include <iostream>

using namespace std;

class DivideByZeroException
{
public:
    const char *what() const noexcept
    {
        return "Error: Divided by Zero";
    }
};

class Divisor
{
private:
    int divisor, divident;

public:
    Divisor(int dr, int dt) : divisor(dr), divident(dt) {}

    double divide()
    {
        if (divisor == 0)
        {
            throw DivideByZeroException();
        }
        return (double)divisor / divident;
    }
};

int main()
{
    try
    {
        int dividend, divisor;
        cout << "Enter divisor: ";
        cin >> divisor;
        cout << "Enter dividend: ";
        cin >> dividend;

        Divisor divOb(divisor, dividend);

        cout << "Result: " << divOb.divide() << endl;
    }
    catch (const DivideByZeroException &err)
    {
        cerr << err.what() << endl;
    }

    return 0;
}
