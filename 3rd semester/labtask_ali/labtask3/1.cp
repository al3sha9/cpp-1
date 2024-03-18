#include <iostream>
#include <string>
using namespace std;

class Temperature {
private:
    static const int cities = 3;
    static const int days = 4;
    string cityName[cities];
    int temperature[cities][days];

public:
    void enterData() {
        for (int i = 0; i < cities; i++) {
            cout << "City " << i + 1 << ":" << endl;
            for (int j = 0; j < days; j++) {
                cout << "Day " << j + 1 << " = ";
                cin >> temperature[i][j];
            }
        }
    }

    void displayData() {
        cout << "Temperature values: " << endl;
        for (int i = 0; i < cities; i++) {
            cout << "City " << i + 1 << endl;
            for (int j = 0; j < days; j++) {
                cout << "Day " << j + 1 << " = " << temperature[i][j] << endl;
            }
        }
    }
};

int main() {
    Temperature temp;
    temp.enterData();
    temp.displayData();

    return 0;
}
