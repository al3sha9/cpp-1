#include <iostream>
// header
using namespace std;

// class decaltion
class Numbers
{
private:
    // variables
    float a, b, c;

public:
    // constructors
    Numbers() {}

    Numbers(float a, float b, float c) : a(a), b(b), c(c) {}

    float getA() const
    {
        return a;
    }

    float getB() const
    {
        return b;
    }

    float getC() const
    {
        return c;
    }
    // friend classes
    friend class Computations;
    friend void display(const Numbers &);
};

class Computations
{
public:
    int sum(const Numbers &n)
    {
        return (n.a * n.a + n.b * n.b + n.c * n.c + 2 * n.a * n.b + 2 * n.b * n.c + 2 * n.c * n.a);
    }

    int difference(const Numbers &n)
    {
        return (n.a * n.a - n.b * n.b - n.c * n.c - 2 * n.a * n.b - 2 * n.b * n.c - 2 * n.c * n.a);
    }

    int mean(const Numbers &n)
    {
        return (n.a * n.b * n.c) / 3;
    }
};
// display funtion
void display(const Numbers &n)
{
    cout << "a is: " << n.getA() << endl;
    cout << "b is: " << n.getB() << endl;
    cout << "c is: " << n.getC() << endl;
}
// main funtion
int main()
{
    float a, b, c;
    cout << "Enter values for a, b, and c: ";
    cin >> a >> b >> c;

    Numbers object1(a, b, c);
    display(object1);

    Computations object2;
    cout << "Sum: " << object2.sum(object1) << endl;
    cout << "Difference: " << object2.difference(object1) << endl;
    cout << "Mean: " << object2.mean(object1) << endl;

    return 0;
}
