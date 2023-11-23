// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
using namespace std;

class Animals{
    public:
  int age;
  string name;
  
};
class mammals: public Animals{
    
};
class birds: public Animals{
    
};
class reptiles: public Animals{
    
};
int main(){
    mammals obj;
    birds obj1;
    reptiles obj2;
    
    obj.name = "gii";
    obj.age = 10;
    
    obj1.name = "ii";
    obj2.name = "ooo";
    cout<<obj.name<<obj1.name<<obj2.name;
       
}
