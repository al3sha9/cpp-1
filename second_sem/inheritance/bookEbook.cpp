// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
using namespace std;
class Book{
  protected:
  int rollNo = 2;
  string name;
};
class Ebook:public Book{
  protected:
  string writer = "abc";
  
  public:
  void display(){
      cout<<rollNo<<endl;
      cout<<writer;
  }
};
int main(){
    Book objB;
    Ebook objE;
    
    objE.display();
   
   
    
}
 
 
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
