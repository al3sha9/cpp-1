#include<iostream>
using namespace std;

class Time{
    private:
        int hours, mins, seconds;

    public:
        Time(int h, int m, int s): hours(h), mins(m), seconds(s){}

    friend int convertTime(Time timeObject);        
};
int convertTime(Time timeObject){
    int sec = timeObject.hours * 3600 + timeObject.mins * 60 + timeObject.seconds;
    int hrs = sec / 3600;
    int s = sec % 3600;
    int min = s / 60;

    cout << "Equivalent Time: " << hrs << " hours, " << min << " minutes." << endl;
}

int main(){
    int seconds;
    cout<<"Enter time in seconds: ";
    cin>>seconds;

    Time object(0,0,seconds);
    convertTime(object);
}