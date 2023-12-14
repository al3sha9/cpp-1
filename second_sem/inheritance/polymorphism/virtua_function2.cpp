#include<iostream>
#include<string>
using namespace std;
class CWH{
    protected:
     string title;
     float rating;

    public:
     CWH(string s, float r){
        title = s;
        rating = r;
     } 
     virtual void display(){
        cout<<"This is base class function";
     }
};
class CWHvideo : public CWH{
    int videoLength;
    public:
     CWHvideo(string s, float r, int vl):CWH(s,r){
        videoLength = vl;
     }
     void display(){
        cout<<"this is an amazing video with title"<<title<<endl;
        cout<<"this video has rating: "<<rating<<" out of 5"<<endl;
        cout<<"length of the video: "<<videoLength<<" minutes"<<endl;
     }
};
class CWHtext : public CWH{
    int words;
    public:
     CWHtext(string s, float r, int wc):CWH(s,r){
        words=wc;
     }
     void display(){
        cout<<"this is an amazing text tutorial with title"<<title<<endl;
        cout<<"Ratings of this tutorial "<<rating<<" out of 5"<<endl;
        cout<<"Number of words: "<<words<<" minutes"<<endl;
     }
};

int main(){
    string title;
    float rating;
    int vlen, words;

    //video
    title = "This cpp tutorial";
    vlen = 5;
    rating = 4.98;
    
    CWHvideo djVideo(title, rating, vlen);
    // djVideo.display();

    //text
    title = "This cpp tutorial textual";
    words =433;
    rating = 4.08;
    
    CWHvideo djText(title, rating, words);
    // djText.display();

    CWH *pointer_Base[2];
    pointer_Base[0] = &djVideo;
    pointer_Base[1] = &djText;

    pointer_Base[0] ->  display();
    pointer_Base[1] ->  display();

}