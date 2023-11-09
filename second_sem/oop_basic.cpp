#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    float inches;

public:
    Distance()
    {
        feet = 0;
        inches = 0.00;
    }
    Distance(int ft, float ic)
    {
        feet = ft;
        inches = ic;
    }
    void getdist()
    {
        cout << "\nEnter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }

    void showdist()
    {
        cout << feet << "\'-" << inches << '\"';
    }

    void addD(Distance d2, Distance d3)
    {
        inches += d2.inches + d3.inches;
        feet = 0;

        if (inches >= 12.0)
        {
            inches -= 12.0;
            feet++;
        }
        feet += d2.feet + d3.feet;
    }
};
int main()
{
    Distance d1, d3;
    Distance d2(11, 6.25);

    d1.getdist();
    d3.addD(d1, d2);

    cout << "dist 1"; d1.showdist();
    cout << "dist 2"; d2.showdist();
    cout << "dist 3"; d3.showdist();
    return 0;
}