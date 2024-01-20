#include <iostream>
#include <string>

class Character {
protected:
    std::string name;
    int health;

public:
    Character(const std::string& n, int h) : name(n), health(h) {}
    void display() const {
        std::cout << "Name: " << name << ", Health: " << health << std::endl;
    }
};

class Hero : public Character {
private:
    int heroPower;

public:
    Hero(const std::string& n, int h, int power) : Character(n, h), heroPower(power) {}
    void usePower() const {
        std::cout << name << " is using their hero power!" << std::endl;
    }
};

class Villain : public Character {
private:
    int villainPower;

public:

    Villain(const std::string& n, int h, int power) : Character(n, h), villainPower(power) {}

    void unleashPower() const {
        std::cout << name << " is unleashing their villain power!" << std::endl;
    }
};

int main() {

    Hero hero("Superman", 100, 50);
    Villain villain("Joker", 80, 30);
    hero.display();
    villain.display();
    hero.usePower();
    villain.unleashPower();

    return 0;
}
