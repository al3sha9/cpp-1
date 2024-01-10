#include<iostream>
#include<string>
using namespace std;

class DivideByZeroException : public exception {
public:
    const char* what() const noexcept override {
        return "Cannot be divided by 0";
    }
};
class Divisor{
    private:
        int dividend, divisor;
    public:
        Divisor(int dividend, int divisor){
            this->dividend = dividend;
            this->divisor = divisor;

        }   

        float divide(){
            if(divisor == 0){
                throw DivideByZeroException();
            }
            else{
            return dividend / divisor;
            }
        } 

};
int main(){
    try{
        int divisor, dividend;
        cout<<"Enter the divisor and dividend: ";
        cin>>divisor>>dividend;

        Divisor divisorObj(divisor, dividend);
        cout<<"The division is: "<<  divisorObj.divide()<<endl; 
    }
    catch(DivideByZeroException e){
        cout<<"Exception: "<<e.what()<<endl;
    }
    return 0;
}