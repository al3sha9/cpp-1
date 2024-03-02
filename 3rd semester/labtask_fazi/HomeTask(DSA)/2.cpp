
#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length, width;

public:
    friend float calculateArea(Rectangle obj);
};
float calculateArea(Rectangle obj)
{
    cout << "Enter the lenght and width: ";
    cin >> obj.length >> obj.width;

    float area = obj.length * obj.width;
    cout << "The area of rectangle is: " << area;
    cout<<endl;
    return area;
}
int main()
{
    Rectangle r;
    calculateArea(r);
}