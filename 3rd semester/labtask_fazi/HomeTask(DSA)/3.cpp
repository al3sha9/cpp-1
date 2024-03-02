#include<iostream>
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
    Temperature t(44.9, 78.2);
    cout << "Celsius to Fahrenheit: " << t.getCelcius() << endl;
    cout << "Fahrenheit to Celsius: " << t.getFahrenheit() << endl;
    return 0;
}
