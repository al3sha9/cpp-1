#include <iostream>
using namespace std;

template <class T>

class Number
{
private:
    T numb;

public:
    // Number(T n): numb(n);
    Number(T n)
    {
        numb = n;
    }
    T get()
    {
        return numb;
    }
};

int main()
{
    Number<int> numbI(23);
    cout << "num is " << numbI.get();
    return 0;
}