#include<iostream>
#include<string>
using namespace std;

class MediaSource{
    protected:
    string name, type;

    public:
    void set(string name, string type){
        this->name = name;
        this->type = type;
    }
    void play(){
        cout<<"The media is playing.."<<endl;
    }
};
class AudioPlayer{
    protected:
    string bitrate; double volume;

    public:
    void adjustVolume(){
        cout<<"Mention the bitrate of audio: ";
        cin>>bitrate; 
        cout<<"Adjust the volume 0-100";
        cin>>volume;
        cout<<"The volume set to "<<volume<<endl;
    }
};
class VideoPlayer{
    protected:
    string resolution, playbackSpeed;

    public:
    void adjustSpeed(){
        cout<<"What is the resolution of video: ";
        cin>>resolution;

        cout<<"Adjust the play back speed: ";
        cin>>playbackSpeed;
        cout<<"Play back set to "<<playbackSpeed<<endl;
    }

};
class MediaPlayer : public AudioPlayer, public VideoPlayer{

};
int main(){
    string name, type;
    MediaPlayer mediaPlayerObj;
    cout<<"Enter the name of the file: ";
    cin>>name;
    cout<<"Enter the type of the file (audio or video): ";
    cin>>type;
    if (type == "audio"){
    mediaPlayerObj.adjustVolume();
    }
    else
    mediaPlayerObj.adjustSpeed();
}