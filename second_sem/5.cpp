#include <iostream>
#include <string>

using namespace std;

class Area
{
private:
    float length;
    float width;
    float area;

public:
    void setDim(float l, float w)
    {
        length = l;
        width = w;
    }

    float getArea()
    {
        area = length * width;
        return area;
    }
};

int main()
{
    Area A1;
    float len, wid;

    cout << "Enter length and width: ";
    cin >> len >> wid;

    A1.setDim(len, wid);

    cout << "Area: " << A1.getArea() << endl;

    return 0;
}
