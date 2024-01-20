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
    
    obj.name = "Mammal";
    obj.age = 10;
    
    obj1.name = "Bird";
    obj2.name = "Reptile";
    cout<<obj.name<<endl<<obj1.name<<endl<<obj2.name<<endl;
       
}
