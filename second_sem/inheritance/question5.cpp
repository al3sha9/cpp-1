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
      cout<<name<<endl<<address<<endl<<age;
  }
};
int main(){
    student std("Fazila", "XYZ", 20);
    std.display();
    return 0;
}
 
 