#include<iostream>
#include<string>
using namespace std;

struct Students
{
    string name;
    int rollNo;
    float GPA;
};
int main(){
    Students st[5];
    for(int i = 0; i<5; i++){
        cout<<"Enter data for Student "<<i+1<<endl;
        cout<<"Name: "<<endl;
        cin>>st[i].name;
        cout<<"RollNo: "<<endl;
        cin>>st[i].rollNo;
        cout<<"GPA: "<<endl;
        cin>>st[i].GPA;
    }
    for(int i = 0; i<5; i++){
        cout<<"Student "<<i+1<<endl;
        cout<<st[i].name<<endl;
        cout<<st[i].rollNo<<endl;
        cout<<st[i].GPA<<endl;

    }
}
