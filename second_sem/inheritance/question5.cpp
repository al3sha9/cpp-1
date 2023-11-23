#include <iostream>
#include <string>

using namespace std;
class Person{
    protected:
    string name;
    string address;
    
    
};
class student:public Person{
    int age;
    public:
  student(string n, string a, int ag){
      name = n;
      address = a;
      age = ag;
  }  
  void display(){
      cout<<"this is derived class"<<endl;
      cout<<name<<address<<age;
  }
};
int main(){
    student std("hero", "abs", 39);
    std.display();
    return 0;
}
 
 