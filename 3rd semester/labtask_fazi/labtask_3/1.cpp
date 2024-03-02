#include <iostream>
#include <string>
using namespace std;

const int week = 7;
const int city = 2;
string cityName[city];

int main() {
    int temperature[city][week];
    
    cout << "Enter the names of the cities: " << endl;
    for (int i = 0; i < city; i++) {
        cout << "City " << i + 1 << ": ";
        cin >> cityName[i];
    }
    
    for (int i = 0; i < city; i++) {
        cout << "Enter the temperatures for " << cityName[i] << ":" << endl;
        for (int j = 0; j < week; j++) {
            cout << "Day " << j + 1 << " : ";
            cin >> temperature[i][j];
        }
    }
    
    cout << "Temperature values: " << endl;
    for (int i = 0; i < city; i++) {
        cout << "City " << cityName[i] << endl;
        for (int j = 0; j < week; j++) {
            cout << "Day " << j + 1 << " : " << temperature[i][j] << endl;
        }
    }
    
    return 0;
}
