#include <iostream>
using namespace std;

class Animals
{
private:
    int age;
    string name;//name

public:
    Animals(int a, string n)
    {
        age = a;//age
        name = n;//nameee .
    }
    int getAge()
    {
        return age;
    }
    string getName()
    {
        return name;
    }
};

class Mammals : public Animals
{
public:
    Mammals(string n, int a) : Animals(a, n) {}
};

class Reptiles : public Animals
{
public:
    Reptiles(string n, int a) : Animals(a, n) {}
};

class Birds : public Animals
{
public:
    Birds(string n, int a) : Animals(a, n) {}
};

int main()
{
    Mammals lion("NIGGA", 12);
    Reptiles liz("MONEY", 420);
    Birds nig("FUCK", 69);

    cout << "MAMMAL" << lion.getAge() << lion.getName() << endl;
    cout << "Reptiles" << liz.getAge() << liz.getName() << endl;
    cout << "Birds" << nig.getAge() << nig.getName() << endl;
}