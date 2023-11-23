#include <iostream>
using namespace std;

class Vehicles
{
private:
    float speed;
    float fuel;
public:
    Vehicles(float s, float f){
        speed = s;
        fuel = f;
    };
    void disall(){
        cout<<speed<<fuel;
    }
    ~Vehicles(){
        cout<<"bye bye";
    };
};

class Car : public Vehicles{
    private:
    string color;
    public:
    Car(float s, float f, string c) : Vehicles(s, f), color(c) {};
    
    void dis(){
        cout<<"CAR DETAILS"<<endl;
        disall();
        cout<<color<<endl;
    }
};
class Bike : public Vehicles{
    private:
    int eng;
    public:
    Bike(float s, float f, int c) : Vehicles(s, f), eng(c) {};
    
    void dis(){
        cout<<"Bike DETAILS"<<endl;
        disall();
        cout<<eng<<endl;
    }
};

int main(){
    Car c1(240, 24, "black");
    Bike b1(180, 3, 70);
    c1.dis();
    c1.dis();

    return 0;
}