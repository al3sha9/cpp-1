#include <iostream>

using namespace std;

class Distance
{
private:
    int feet;
    int inches;

public:
    Distance(int feet = 0, int inches = 0) : feet(feet), inches(inches) {}

    Distance(const Distance &other)
    {
        feet = other.feet;
        inches = other.inches;
    }

    Distance &operator=(const Distance &other)
    {
        if (this != &other)
        {
            feet = other.feet;
            inches = other.inches;
        }
        return *this;
    }

    void displayBeforeAssignment()
    {
        cout << "Distance: " << feet << " feet " << inches << " inches" << endl;
    }

    void displayAfterAssignment()
    {
        cout << "Updated Distance: " << feet << " feet " << inches << " inches" << endl;
    }
};

int main()
{
    Distance distance1(5, 10);
    Distance distance2(3, 6);

    cout << "Before Assignment:" << endl;
    distance1.displayBeforeAssignment();
    distance2.displayBeforeAssignment();

    distance1 = distance2;

    cout << "After Assignment:" << endl;
    distance1.displayAfterAssignment();
    distance2.displayBeforeAssignment();

    return 0;
}
