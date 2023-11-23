#include <iostream>
#include <string>

using namespace std;


class Animal {
protected:
    string name;
    int age;

public:
    Animal(const string& n, int a) : name(n), age(a) {}

    void eat() {
        cout << name << " is eating." << endl;
    }

    void sleep() {
        cout << name << " is sleeping." << endl;
    }

    void makeSound() {
        cout << "Some generic animal sound" << endl;
    }
};


class Mammal : public Animal {
public:
    Mammal(const string& n, int a) : Animal(n, a) {}

    
    void giveBirth() {
        cout << name << " is giving birth to live young." << endl;
    }

    void makeSound() {
        cout << name << " makes mammal-specific sound" << endl;
    }
};


class Bird : public Animal {
public:
    Bird(const string& n, int a) : Animal(n, a) {}

    void layEggs() {
        cout << name << " is laying eggs." << endl;
    }

    void makeSound() {
        cout << name << " makes bird-specific sound" << endl;
    }
};


class Reptile : public Animal {
public:
    Reptile(const string& n, int a) : Animal(n, a) {}

    
    void crawl() {
        cout << name << " is crawling." << endl;
    }

    void makeSound() {
        cout << name << " makes reptile-specific sound" << endl;
    }
};

int main() {
    Mammal lion("Simba", 5);
    Bird eagle("Baldy", 10);
    Reptile snake("Sly", 2);

    lion.eat();
    lion.giveBirth();
    lion.makeSound();

    eagle.eat();
    eagle.layEggs();
    eagle.makeSound();

    snake.eat();
    snake.crawl();
    snake.makeSound();

    return 0;
}
