#include <iostream>
using namespace std;

class foo
{
private:
    static int count;

public:
    foo()
    {
        count++;
    }
    int get() const
    {
        return count;
    }
};

int foo::count = 0;

int main()
{
    foo f1, f2, f3;
    cout << "Count: " << f1.get() << endl;
    cout << "Count: " << f2.get() << endl;
    cout << "Count: " << f3.get() << endl;
    return 0;
}
