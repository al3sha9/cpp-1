#include <iostream>
using namespace std;

class B;
class A
{
private:
    int data;

public:
    A() : data(12) {}
    friend float addBoth(A, B);
};

class B
{
private:
    int data;

public:
    B() : data(34) {}
    friend float addBoth(A, B);
};
float addBoth(A a1, B b1)
{
    return (a1.data + b1.data);
}

int main()
{
    A a;
    B b;
    cout << "ADDED" << addBoth(a, b);
}