#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base created\n";
    }
    virtual ~Base()
    {
        cout << "base destroyed\n";
    }
};

class Der : public Base
{
public:
    Der()
    {
        cout << "derived created\n";
    }
    virtual ~Der()
    {
        cout << "derived deleted\n";
    }
};

int main()
{
    Base *b = new Der;
    delete b;
}