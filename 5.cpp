#include <iostream>
using namespace std;

class Property
{
private:
    string location;
    float price;

public:
    Property(string l, float p)
    {
        location = l;
        price = p;
    };
    void disall()
    {
        cout << location<<endl << price<<endl;
    }
};

class Apartments : public Property
{
private:
    int rooms;
    int floor;

public:
    Apartments(string l, float p, int r, int f) : Property(l, p), rooms(r), floor(f){};
    void dis()
    {
        cout << "Apartment details: " << endl;
        disall();
        cout << rooms <<endl<< floor << endl;
    }
};

int main()
{
    Apartments A1("wtf", 1600, 4, 24);

    A1.dis();

    return 0;
}