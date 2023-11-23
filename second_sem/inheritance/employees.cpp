// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
using namespace std;
class Employee{
  protected:
  string name;
  int age;
  
};
class teacher:public Employee{
    public:
    void getvalues(){
        cout<<"enter name: "<<endl;
        cin>>name;
        cout<<"enter age: "<<endl;
        cin>>age;
    }
};
class staff:public Employee{
    
    
};
int main(){
    teacher obT;
    obT.getvalues();
}














    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
