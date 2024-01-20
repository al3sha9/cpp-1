#include <iostream>
#include <string>

using namespace std;

class Character {
private:
    string name;
    int health;

public:

    Character(const string& n, int h) : name(n), health(h) {}

    void display() const {
        cout << "Name: " << name << ", Health: " << health << endl;
    }

    string getName() const {
        return name;
    }
};

class PlayerCharacter : public Character {
private:
    int experience;

public:

    PlayerCharacter(const string& n, int h, int exp) : Character(n, h), experience(exp) {}

    void levelUp() {
        experience += 100;
        cout << getName() << " leveled up! Experience: " << experience << endl;
    }
};

int main() {

    PlayerCharacter player("Hero", 100, 0);
    player.display();
    player.levelUp();

    return 0;
}
