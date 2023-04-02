

#include <iostream>
#include <cmath>
using namespace std;

int main() {

  float sub1, sub2, sub3, sub4, sub5, total, percentage;
  
  cout << "ENTER MARKS"<<endl;
  cin>> sub1>>sub2>>sub3>>sub4>>sub5;
  
  total = sub1 + sub2 + sub3 + sub4 + sub5;
  
  percentage = total * 100 / 500;
  
  if(percentage >= 90 && percentage <=100){
  	cout<<"A grade";
  }
  else if(percentage >= 80 && percentage <=90){
  	cout<<"B grade";
  }
  else if(percentage >= 70 && percentage <=80){
  	cout<<"C grade";
  }
  else if(percentage >= 60 && percentage <=70){
  	cout<<"D grade";
  }
  else if(percentage >= 50 && percentage <=60){
  	cout<<"E grade";
  }
  else if(percentage >= 0 && percentage <=50){
  	cout<<"F grade";
  }
  else{
  	cout<<"INVALID ENTRY";
  }

  return 0;
}