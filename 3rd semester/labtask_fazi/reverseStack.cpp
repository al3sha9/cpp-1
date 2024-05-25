#include<iostream>
#include<stack>
using namespace std;

void copyandreverse(stack <int> &original, stack<int> &reverse){
    stack <int> temp;
    while(!original.empty()){
        temp.push(original.top());
        original.pop();
    }
    while(!temp.empty()){
        reverse.push(temp.top());
        temp.pop();
    }
}
int main(){
    stack<int>original;
    stack<int>reverse;

    original.push(50);
    original.push(40);
    original.push(30);
    original.push(20);
    original.push(10);

    copyandreverse(original, reverse);

    cout<<"reversed stack: "<< " ";
    while(!reverse.empty()){
        cout<<reverse.top()<<" ";
        reverse.pop();
    }
    cout<<endl;
}