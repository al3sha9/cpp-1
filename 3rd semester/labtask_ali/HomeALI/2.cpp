#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length, width;

public:
    Rectangle(int l, int w)
    {
        length = l;
        width = w;
    }

    float calculateArea()
    {
        float area = length * width;
        return area;
    }
};

int main()
{
    int l, w;
    cout << "Enter the length and width of the rectangle: ";
    cin >> l >> w;

    Rectangle r(l, w);
    float area = r.calculateArea();
    cout << "The area of the rectangle is: " << area << endl;

    return 0;
}
