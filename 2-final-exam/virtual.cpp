#include<iostream>
using namespace std;

class Top{
    public:
        void print(){
            cout<<"TOP CLASS"<<endl;
        }
};
class Bottom: public Top{
    public:
        void print(){
            cout<<"BOTTOM CLASS"<<endl;
        }
};

int main(){
    Bottom a1, b2;
    b2.Top::print();
    a1.print();
    return 0;
}