#include <iostream>
#include <string>
using namespace std;

struct Vehicle {
    string make;
    string model;
    int year;
    bool available;
};

void displayVehicle(const Vehicle& vehicle) {
    cout << "Make: " << vehicle.make << ", Model: " << vehicle.model << ", Year: " << vehicle.year << endl;
}

void rentVehicle(Vehicle& vehicle) {
    if (vehicle.available) {
        vehicle.available = false;
        cout << "Vehicle rented successfully!" << endl;
    } else {
        //cout << "Vehicle is not available for rent." << endl;
    }
}

void returnVehicle(Vehicle& vehicle) {
    if (!vehicle.available) {
        vehicle.available = true;
        cout << "Vehicle returned successfully!" << endl;
    } else {
        cout << "Vehicle is not currently rented." << endl;
    }
}

int main() {
    Vehicle vehicles[3] = {{"Toyota", "Camry", 2018, true},
                           {"Honda", "Civic", 2020, true},
                           {"Ford", "F-150", 2019, true}};

    cout << "Available Vehicles:" << endl;
    for (const auto& vehicle : vehicles) {
        if (vehicle.available) {
            displayVehicle(vehicle);
        }
    }

    rentVehicle(vehicles[0]);
    cout << endl;

    cout << "Available Vehicles:" << endl;
    for (const auto& vehicle : vehicles) {
        if (vehicle.available) {
            displayVehicle(vehicle);
        }
    }

    returnVehicle(vehicles[0]);
    cout << endl;

    cout << "Available Vehicles:" << endl;
    for (const auto& vehicle : vehicles) {
        if (vehicle.available) {
            displayVehicle(vehicle);
        }
    }

    return 0;
}
