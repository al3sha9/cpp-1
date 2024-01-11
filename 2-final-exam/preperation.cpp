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
    void func(Alpha obj)
    {
        cout << "x: " << obj.x;
    }
};
int main()
{
    Alpha obj1(10);
    Beta obj2;
    obj2.func(obj1);
    return 0;
}
