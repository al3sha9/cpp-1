#include <iostream>
#include <string>
using namespace std;

const int products = 2;
const int attributes = 2;

string productName[products] = {"Laptop", "Cell Phone"};
float productPrice[products] = {100.99, 500.99};
int productQuantity[products] = {10, 20};

void displayProducts() {
    cout << "Inventory Products:" << endl;
    cout << "Product Name\t   Price\tQuantity" << endl;
    for (int i = 0; i < products; ++i) {
        cout << productName[i] << "\t\t\t$" << productPrice[i] << "\t\t" << productQuantity[i] << endl;
    }
}

int main() {
    displayProducts();
    return 0;
}
