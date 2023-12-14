#include<iostream>
#include<string>
using namespace std;

class Person{
    protected:
     string name = "Fazila";
     int age = 20;
    public:
     void displayDetails(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
     }
};
class Teaching{
    protected:
     string subject = "CS";
     int experience = 4;
    public:
     void teach(){
        cout<<"Teacher is teaching "<<subject<<" and have "<<experience<< " years experience."<<endl;
     } 
};
class NonTeaching{
    protected:
     string position = " chef ", responsibility = "cooks for the staff";
    public:
     void performDuties(){
        cout<<"He/she is"<<position<<" and "<<responsibility<<endl;
     }
};
class StaffMember : public Teaching, public NonTeaching{

};
int main(){
    Person personObject;
    personObject.displayDetails();
    StaffMember staffMemberObject;
    staffMemberObject.teach();
    staffMemberObject.performDuties();
}