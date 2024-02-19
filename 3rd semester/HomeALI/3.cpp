#include <iostream>
using namespace std;

class Temperature {
private:
    float celsius, fahrenheit, fahrenheitT, celsiusT;
public:
    Temperature(float celsius, float fahrenheit) {
        this->celsius = celsius;
        this->fahrenheit = fahrenheit;
    }
    float getCelcius() {
        fahrenheitT = (celsius * 9 / 5) + 32;
        return fahrenheitT;
    }
    float getFahrenheit() {
        celsiusT = (fahrenheit - 32) * 5 / 9;
        return celsiusT;
    }
};


int main() {
    float celsius, fahrenheit;
    cout << "Enter the temperature in Celsius: ";
    cin >> celsius;
    cout << "Enter the temperature in Fahrenheit: ";
    cin >> fahrenheit;

    Temperature t(celsius, fahrenheit);
    cout << "Celsius to Fahrenheit: " << t.getCelcius() << endl;
    cout << "Fahrenheit to Celsius: " << t.getFahrenheit() << endl;
    return 0;
}
