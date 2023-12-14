#include<iostream>
#include<cmath>
using namespace std;

class Equation {
private:
    int a, b, c; 
    float proot, nroot;

public:
    Equation() {}

    Equation(int a, int b, int c, float proot, float nroot) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->proot = proot;
        this->nroot = nroot;
        calculate();  // Call calculate in the constructor
    }

    void calculate() {
        float discriminant = b * b - 4 * a * c;
            proot = (-b + sqrt(discriminant)) / (2 * a);
            nroot = (-b - sqrt(discriminant)) / (2 * a);
    }

    void display() {
        cout << "Positive root: " << proot << endl;
        cout << "Negative root: " << nroot << endl;
    }
};

int main() {
    int a, b, c;
    float proot, nroot ; 
    cout << "Enter coefficients a, b, c: ";
    cin >> a >> b >> c;

    Equation equationObject(a, b, c, proot, nroot);
    equationObject.display();

    return 0;
}
