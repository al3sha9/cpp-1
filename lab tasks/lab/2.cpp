//GCR question 1
#include<iostream>
#include<string>
using namespace std;
class Person{
  private:
  //these attributes are private and hidden from external excess
  string name;
  int age;
  string address;
  
  Person(string name, string address, int age){
      name = name;
      address = address;
      age = age;
  }
};

int main(){
    Person p1;
}