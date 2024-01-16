#include<iostream>
#include<string>
using namespace std;

int main(){
    string word = "four";
    try{
    cout<<word.at(5)<<endl; //at() gives the indexing number of a string
        
    }
    catch(...){ // ... means any type of exception
        cout<<"exception! can't access this term"<<endl;
    }
    //also
    //catch(out_of_range & e)
    //or
    /*
    catch(out_of_range & e){
        cout<<"exception: " << e.what()<<endl;
    }
    */
   /*
   */
}