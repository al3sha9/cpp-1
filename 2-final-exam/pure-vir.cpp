#include <iostream>
using namespace std;

class Base
{
private:
    int x;

public:
    virtual void fun() = 0;
};

class Der : public Base
{
private:
    int y;

public:
    void fun()
    {
        cout << "FUN() CALLED" << endl;
    }
};

int main()
{
    Der d;
    d.fun();
}
