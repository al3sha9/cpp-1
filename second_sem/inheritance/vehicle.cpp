#include<iostream>
using namespace std;

class Vehicle{
    protected:
    int speed;
    float fuel;

};
class Cars : public Vehicle{
    protected:
    string name;
    
    public:
    Cars(){

    }
    Cars(string name){
        this->name = name;
    }
    string display(){
        return name;
    }
};

int main(){
    Vehicle vehicleObject;
    Cars carObject("Toyota");
    cout<<carObject.display()<<endl;
}