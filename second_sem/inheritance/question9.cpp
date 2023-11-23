#include <iostream>
#include <string>
using namespace std;

class Property {
private:
    string location;
    int price;

public:
    Property(const string& l, int p) : location(l), price(p) {}

    // Getters for private members
    const string& getLocation() const {
        return location;
    }

    int getPrice() const {
        return price;
    }
};

class Apartments : public Property {
private:
    int no;

public:
    Apartments(const string& l, int p, int n) : Property(l, p), no(n) {}

    void display() {
        cout << "Location: " << getLocation() << ", Price: " << getPrice() << ", Apartment Number: " << no << endl;
    }
};

int main() {
    Apartments obj("Islamabad", 20000, 103);
    obj.display();

    return 0;
}


