#include <iostream>
using namespace std;

template <typename T>
T add(T num1, T num2)
{
    return (num1 + num2);
};

int main()
{
    int res1;
    float fres;

    res1 = add<int>(23, 56);
    cout << res1<<endl;

    fres = add<float>(56.33, 34.22);
    cout << fres;
}