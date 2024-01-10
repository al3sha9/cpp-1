#include<iostream>
#include<string>
using namespace std;

class DivideByZeroException : public exception {
    public:
    const char* what() const noexcept override {
        return "Cannot be divided by 0";
    }
};
class NegativeDividendException : public exception{
    public:
    const char* what() const noexcept override{
        return "Negative number found ";
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
            else if(dividend < 0){
                throw NegativeDividendException();
            }
            else{
            return dividend/divisor;
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
    catch(NegativeDividendException e){
        cout<<"Exception 2: "<<e.what()<<endl;
        throw;
    }
    catch (exception& e) {
        cout << "Generic Exception: " << e.what() << endl;
    }
    return 0;
}