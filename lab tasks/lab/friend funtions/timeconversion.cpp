#include<iostream>
#include<cmath>
using namespace std;

class Time{
    private:
    float hours, minutes, seconds;

    public:
    Time() : hours(0), minutes(0), seconds(0) {}
    friend void convertTime(Time&);
};
void convertTime(Time& T){
    cout<<"Enter time in Seconds: ";
    cin>>T.seconds;
    
    T.minutes = T.seconds/60;
    cout<<"Time in minutes: "<<T.minutes<<endl;
    T.hours = T.seconds/3600;
    cout<<"Time in hours: "<<T.hours<<endl;
    
}
int main(){
    Time Tobject;
    convertTime(Tobject);
}