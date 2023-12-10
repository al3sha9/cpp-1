#include<iostream>
#include<string>
using namespace std;

class Animal{
    protected:
        string name = "Lion", type ="Carnivore";
    public:
        void displayInfo(){
            cout<<"Name: "<<name<<endl;
            cout<<"Type: "<<type<<endl;
        }    

};
class Carnivore{
    protected:
     string prey = "Rabbit";

    public:
     void eat(){
        cout<<"Carnivore is eating its prey "<<prey<<endl;
     } 
};
class Herbivore{
    protected:
     string diet = "Carrot";
    public: 
     void gaze(){
        cout<<"Herbivore is gazing and eating "<<diet<<endl;
     } 
};
class ZooAnimal:public Carnivore, public Herbivore{
    
};
int main(){
    Animal animalObject;
    animalObject.displayInfo();
    ZooAnimal zooAnimalObject;
    zooAnimalObject.eat();
    zooAnimalObject.gaze();
}