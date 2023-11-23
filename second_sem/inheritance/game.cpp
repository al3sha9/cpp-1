#include <iostream>
#include <string>

using namespace std;

// Base class: Character
class Character {
private:
    string name;
    int health;

public:
    // Constructor
    Character(const string& n, int h) : name(n), health(h) {}

    // Common method
    void display() const {
        cout << "Name: " << name << ", Health: " << health << endl;
    }

    // Getter method for name
    string getName() const {
        return name;
    }
};

// Derived class: PlayerCharacter
class PlayerCharacter : public Character {
private:
    int experience;

public:
    // Constructor
    PlayerCharacter(const string& n, int h, int exp) : Character(n, h), experience(exp) {}

    // Additional method for PlayerCharacter
    void levelUp() {
        experience += 100;
        cout << getName() << " leveled up! Experience: " << experience << endl;
    }
};

int main() {
    // Creating an instance of PlayerCharacter
    PlayerCharacter player("Hero", 100, 0);

    // Using common method from the base class
    player.display();

    // Using specialized method from the derived class
    player.levelUp();

    return 0;
}
