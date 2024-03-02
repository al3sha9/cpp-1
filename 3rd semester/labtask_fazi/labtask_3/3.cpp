#include <iostream>
#include <string>
using namespace std;

const int user = 3;
const int movies = 1;

int main(){
    int ratings[user][movies];
    for(int i = 0; i<user; i++){
        cout<<"User "<<i+1<<endl;
        cout<<"How much do you rate out of 5 for movie \'The Martrix': "<<endl;
        for(int j= 0; j<movies; j++ ){
            cin>>ratings[i][j];
        }
    }
    for(int i = 0; i<user; i++){
        cout<<"Rating by user "<<i+1<<" : ";
        for(int j = 0; j<movies;j++){
            cout<<ratings[i][j]<<endl;
        }
    }
}