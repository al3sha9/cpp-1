#include <iostream>
using namespace std;

class Shape
{
protected:
    virtual float calA() = 0;
    virtual float calP() = 0;
};

class Circle : public Shape
{
public:
    float rad;
    Circle(float r)
    {
        rad = r;
    }
    float calA()
    {
        return (rad * rad) * 3.14;
    }
    float calP()
    {
        return (rad * rad) * 3.14;
    }
};

int main()
{
    Circle c1(2);
    cout << c1.calA() << endl;
    return 0;
}