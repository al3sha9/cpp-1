#include<iostream>
#include<string>
using namespace std;

class Product{
    protected:
    string name;
    float price;

};
class Electronics: public Product{
    protected:
    string type;
    string color;
    public:
    Electronics(string type, string color){
        this->type = type;
        this->color = color;
    }
    string display(){
        return type;
        return color;
    }
    void getDetails(){
        cout<<"Enter the name of the Product: ";
        cin>>name;
        cout<<"Enter the price: ";
        cin>>price;
    }

};
int main(){
    Electronics obj("Watch", "Blue");
    cout<<obj.display()<<endl; 
    obj.getDetails();
}