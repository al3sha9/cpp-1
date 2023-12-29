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

class NegativeDividendException
{
public:
    const char *what() const noexcept
    {
        return "Error:  Dividend is Negative";
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
            throw DivideByZeroException(); // Throw the exception
        }
        else if (divident < 0)
        {
            throw NegativeDividendException(); // Throw the DivideByZeroException
        }
        return (double)divisor / divident; // Ensure correct division
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
        cerr << err.what() << endl; // Print the error message
    }
    catch (const NegativeDividendException &err)
    {
        cerr << err.what() << endl;
        throw;
    }

    return 0;
}
