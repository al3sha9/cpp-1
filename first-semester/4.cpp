#include<iostream>
using namespace std;

int main()
{
    int number;
    char name[30], email[30];
    cout<<"Enter Your Name\n";
    cin.getline(name, 30);

    cout<<"Enter Your Email\n";
    cin.getline(email, 30);

    cout<<"Enter Your Contact\n";
    cin>>number;

    cout<<"\n Your details are: \n"<<"Name: "<<name<<"\nEmail:"<<email<<"\nNumber: "<<number;

    return 0;
}
