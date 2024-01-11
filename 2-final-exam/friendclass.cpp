#include <iostream>
using namespace std;

class Alpha
{
private:
    int x;

public:
    Alpha(int a)
    {
        x = a;
    }
    friend class Beta;
};

class Beta
{
private:
    int y;

public:
    void funcal(Alpha a1)
    {
        cout << "value of x is: " << a1.x << endl;
    }
};
int main()
{
    Alpha ob(123123);
    Beta ob1;
    ob1.funcal(ob);
    return 0;
}