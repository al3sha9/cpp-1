#include<iostream>
using namespace std;

class TemperatureConverter{
    private:
    float Celsius, Fahrenheit;

    public:
    TemperatureConverter(float Celsius, float Fahrenheit){
        this->Celsius = Celsius;
        this->Fahrenheit = Fahrenheit;
    }

    friend class CelsiusConverter;
    friend class FahrenheitConverter;

    void display(){
        cout<<"Celsius: "<<Celsius<<endl;
        cout<<"Fahrenheit: "<<Fahrenheit<<endl;
    }
};
class CelsiusConverter{
    //Fahrenheit to Celsius
    public:
    static void convertFahrenheit(TemperatureConverter& temp){
        temp.Fahrenheit = temp.Celsius *9.0/5.0 + 32;
    }
};
class FahrenheitConverter{
    //Celsius to Fahrenheit
    public:
    static void convertCelsius(TemperatureConverter& temp){
        temp.Celsius = (temp.Fahrenheit - 32) * 5.0 / 9.0;
    }
};

int main(){
    TemperatureConverter object(30.2, 70); 

    object.display();
    
    CelsiusConverter::convertFahrenheit(object);
    FahrenheitConverter::convertCelsius(object);
    object.display();
}