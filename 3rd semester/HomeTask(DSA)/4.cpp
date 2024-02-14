
// 4. Basic Calculator:
// Develop a simple calculator program.
// Define a class Calculator with methods to perform
// addition, subtraction, multiplication, and division of  two numbers.
#include <iostream>
using namespace std;

class Calculator
{
private:
    int a, b;

public:
    friend void getValues(Calculator c);
    friend int addition(Calculator c);
    friend int subtraction(Calculator c);
    friend int multiplication(Calculator c);
    friend float division(Calculator c);
};
void getValues(Calculator c){
    cout<<"Enter the values for a and b: ";
    cin>>c.a>>c.b;
}
int addition(Calculator c)
{
    return c.a + c.b;
}
int subtraction(Calculator c)
{
    return c.a - c.b;
}
int multiplication(Calculator c){
    return c.a * c.b;
}
float division(Calculator c){
    return c.a / c.b;
}
int main(){
    Calculator obj;
    int choice;
    cout<<"Choose any one to perform\n 1. Addition 2. Subtraction 3. Multiplication 4. Division ";
    cin>>choice;
    switch (choice)
    {
    case 1:
        getValues(obj);
        cout<<"Result = "<<addition(obj)<<endl;
        break;
    case 2:
        getValues(obj);
        cout<<"Result = "<<subtraction(obj)<<endl;
        break;
    case 3:
        getValues(obj);
        cout<<"Result = "<<multiplication(obj)<<endl;
        break;
    case 4:
        getValues(obj);
        cout<<"Result = "<<division(obj)<<endl;
        break;
    
    default:
        cout<<"Invalid choice!";
        break;
    }
    return 0 ;
}