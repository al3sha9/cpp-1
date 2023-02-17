#include<iostream>
using namespace std;

int main(){
	int a, b;
	cout<<"Enter Number A:";
	cin>>a;
	
	cout<<"Enter Number B: ";
	cin>>b;
	
	int add, sub, mul;
	double divide, mod;
	
	add = a + b;
	sub = a - b;
	mul = a * b;
	divide = a / b;
	mod = a % b;
	
	cout<<"\nA + B ="<<add;
	cout<<"\nA - B ="<<sub;
	cout<<"\nA x B ="<<mul;
	cout<<"\nA / B ="<<divide;
	cout<<"\nA % B ="<<mod;
	
	return 0;
}