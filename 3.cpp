#include <iostream>
using namespace std;

class Character
{
private:
    string name;
    float health;

public:
    Character(string n, float h)
    {
        name = n;
        health = h;
    };
    void diss()
    {
        cout << name << health;
    }
    ~Character()
    {
        cout << "BYE BYE";
    };
};

class Player : public Character
{
private:
    string gender;

public:
    Player(string n, float h, string g) : Character(n, h), gender(g) {}
    void dis()
    {
        cout << "DETAILS" << endl;
        diss();
        cout << gender << endl;
    }
};

int main()
{
    Player p("ALI SHAN", 78, "Male");
    Player d("ALI SHAN", 78, "Male");
    p.dis();
    d.dis();
}