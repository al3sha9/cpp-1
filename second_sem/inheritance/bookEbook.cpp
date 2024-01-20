#include <iostream>
#include <string>
using namespace std;
class Book{
  protected:
  int rollNo;
  string name;
  public:
  Book(){}
  Book(int rollNo, string name){
    this->rollNo = rollNo;
    this->name = name;
  }
  void displayBook(){
    cout<<rollNo<<endl;
    cout<<name<<endl;
  }
};
class Ebook:public Book{
  protected:
  string writer = "CPP writer";
  
  public:
  void display(){
      cout<<writer<<endl;
  }
};
int main(){
    Book objB(101, "CPP");
    objB.displayBook();
    Ebook objE;
    objE.display();
}
 
 
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
