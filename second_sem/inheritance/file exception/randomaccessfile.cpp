#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream obj("myfile.txt");
    cout<<"Current location before writing"<<obj.tellp()<<endl;
    obj<<"Hello world";
    cout<<"Current location after writing"<<obj.tellp()<<endl;
    obj.seekp(-5, ios::end);
    cout<<"Current location after moving "<<obj.tellp()<<endl;
    obj<<"Class";
    cout<<"Current location after writing from end"<<obj.tellp()<<endl;
    obj.seekp(0, ios::cur);
    cout<<"Current location "<<obj.tellp()<<endl;
    obj.close();

    ifstream obj1("myfile.txt");
    cout<<"Current location ar reading"<<obj1.tellg()<<endl;
    obj1.seekg(5,ios::beg);
    cout<<"Current poistion at reading"<<obj1.tellg()<<endl;
    obj1.seekg(5, ios::beg);
    cout<<"current position at reading"<<obj1.tellg()<<endl;

    char c;
    while (!obj1.eof()){
        obj1.get(c);
        if (obj1.eof()){
            break;
        }
        cout<<c;
    }
    obj1.close();
}