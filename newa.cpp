// header files
#include <iostream>
#include <cmath>
using namespace std;

// class declaration
class Equation
{
    // variables declaration
    int a, b, c;
    float proot, nroot;

    friend void Display(Equation &);
    friend void Roots(Equation &);

public:
    // default constructor
    Equation() : a(0), b(0), c(0), proot(0), nroot(0) {}

    // paramertized constructor
    Equation(int a_val, int b_val, int c_val)
    {
        a = a_val;
        b = b_val;
        c = c_val;
        proot = 0;
        nroot = 0;
    }
};

// funtions
void Roots(Equation &obj1)
{
    double determinant;
    determinant = pow(obj1.b, 2) - 4 * obj1.a * obj1.c;
    if (determinant >= 0)
    {
        determinant = sqrt(determinant);
        obj1.proot = (-obj1.b + determinant) / (2 * obj1.a);
        obj1.nroot = (-obj1.b - determinant) / (2 * obj1.a);
    }
    else
    {
        cout << "solution not possible\n";
    }
}

void Display(Equation &obj1)
{
    cout << "positive root value : " << obj1.proot << endl;
    cout << "negative root value : " << obj1.nroot << endl;
}

// main funtion
int main()
{
    int a, b, c;
    cout << "Enter A : ";
    cin >> a;
    cout << "Enter B : ";
    cin >> b;
    cout << "Enter C : ";
    cin >> c;

    // object creation
    Equation obj(a, b, c);
    Roots(obj);
    Display(obj);

    return 0;
}
// okaoka
