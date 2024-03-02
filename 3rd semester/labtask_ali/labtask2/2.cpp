#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    string name[3];
    int price[3];
    int quantity[3];

public:
    Product() {
        name[0] = "Notebook";
        name[1] = "Pen";
        name[2] = "Marker";

        price[0] = 1400;
        price[1] = 1500;
        price[2] = 2000;

        quantity[0] = 2;
        quantity[1] = 8;
        quantity[2] = 7;
    }

    void displayProducts() {
        cout << "The products are: " << endl;
        cout << "Name\t\tPrice\t\tQuantity" << endl;
        for (int i = 0; i < 3; i++) {
            cout << name[i] << "\t\t" << price[i] << "\t\t" << quantity[i] << endl;
        }
    }
};

int main() {
    Product product;
    product.displayProducts();
    return 0;
}
