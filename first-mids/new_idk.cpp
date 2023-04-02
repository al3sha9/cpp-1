#include <iostream>
using namespace std;

int main() {
    double unit, bill;
    cout << "Give me unit!" << endl;
    cin >> unit;

    if (unit<=300){
        bill = unit * 2;
    }
    else if(unit > 300 && unit <= 500){
        bill = 300 * 2 + (unit-300)*5;
    }
    else{
        bill = 300 * 2 + 200 * 5 + (unit - 500) * 7;

    }

    bill +=150;

    if (bill > 2000){
        bill += bill * 0.05;
    }

    cout<<"Total Bill is:"<<bill<<endl;
    return 0;
}
