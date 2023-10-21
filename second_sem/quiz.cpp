#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    string brand; // Attribute
    string model; // Attribute
    int year;

public:
    Car(string b, string m, int y)
    {
        brand = b;
        model = m;
        year = y;
    }
    string getb()
    {
        return brand;
    }
    string getm()
    {
        return model;
    }
    int gety()
    {
        return year;
    }
};

int main()
{
    string b, m;
    int y;
    cout << "enter brand" << endl;
    cin >> b;
    cout << "enter model" << endl;
    cin >> m;
    cout << "enter year" << endl;
    cin >> y;
    Car c1(b, m, y);
    cout << "Car details" << endl
         << c1.getb() << endl
         << c1.getm() << endl
         << c1.gety()<<endl;
    return 0;
}