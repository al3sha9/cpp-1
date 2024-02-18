#include <iostream>
#include <string>

using namespace std;

struct Vehicle {
    string make;
    string model;
    int year;
    bool available;
};

void displayAvailableVehicles(Vehicle vehicles[], int size) {
    cout << "Available Vehicles:" << endl;
    for (int i = 0; i < size; ++i) {
        if (vehicles[i].available) {
            cout << "Vehicle " << i+1 << ": " << vehicles[i].make << " " << vehicles[i].model << " (" << vehicles[i].year << ")" << endl;
        }
    }
}

void rentVehicle(Vehicle vehicles[], int index) {
    if (index >= 0 && index < 3) {
        if (vehicles[index].available) {
            vehicles[index].available = false;
            cout << "Vehicle rented successfully!" << endl;
        } else {
            cout << "Vehicle is not available for rent." << endl;
        }
    } else {
        cout << "Invalid vehicle index." << endl;
    }
}

void returnVehicle(Vehicle vehicles[], int index) {
    if (index >= 0 && index < 3) {
        if (!vehicles[index].available) {
            vehicles[index].available = true;
            cout << "Vehicle returned successfully!" << endl;
        } else {
            cout << "Vehicle is not currently rented." << endl;
        }
    } else {
        cout << "Invalid vehicle index." << endl;
    }
}

int main() {
    Vehicle vehicles[3] = {{"Toyota", "Camry", 2018, true},
                           {"Honda", "Civic", 2020, true},
                           {"Ford", "F-150", 2019, true}};

    displayAvailableVehicles(vehicles, 3);

    rentVehicle(vehicles, 0);

    displayAvailableVehicles(vehicles, 3);

    returnVehicle(vehicles, 0);

    displayAvailableVehicles(vehicles, 3);

    return 0;
}
