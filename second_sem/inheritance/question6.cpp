#include <iostream>
#include <string>

class Character {
protected:
    std::string name;
    int health;

public:
    // Constructor
    Character(const std::string& n, int h) : name(n), health(h) {}

    // Common method
    void display() const {
        std::cout << "Name: " << name << ", Health: " << health << std::endl;
    }
};

class Hero : public Character {
private:
    int heroPower;

public:
    // Constructor
    Hero(const std::string& n, int h, int power) : Character(n, h), heroPower(power) {}

    // Additional method for heroes
    void usePower() const {
        std::cout << name << " is using their hero power!" << std::endl;
    }
};

class Villain : public Character {
private:
    int villainPower;

public:
    // Constructor
    Villain(const std::string& n, int h, int power) : Character(n, h), villainPower(power) {}

    // Additional method for villains
    void unleashPower() const {
        std::cout << name << " is unleashing their villain power!" << std::endl;
    }
};

int main() {
    // Creating instances of Hero and Villain
    Hero hero("Superman", 100, 50);
    Villain villain("Joker", 80, 30);

    // Using common methods from the base class
    hero.display();
    villain.display();

    // Using specialized methods from the derived classes
    hero.usePower();
    villain.unleashPower();

    return 0;
}
