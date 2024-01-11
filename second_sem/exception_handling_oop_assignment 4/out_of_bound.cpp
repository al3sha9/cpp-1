// #include<iostream>
// using namespace std;

// int main(){
//     double numerator, denominator, arr[4] = {0.0, 0.0, 0.0, 0.0};
//     int index;
//     cout<<"Enter array index: ";
//     cin>>index;

//     try{
//         if (index>=0){
//              throw "error: array out of bounds!";
//         }

//         cout<<"Enter numerator: ";
//         cin>>numerator;
//         cout<<"Enter denominator: ";
//         cin>>denominator;

//         if(denominator == 0)
//             throw 0;   

//         arr[index] = numerator / denominator;
//         cout<<arr[index]<<endl;
        
//     }
//     catch(const char* msg){
//         cout<<msg<<endl;
//     }
//     catch(int num){
//         cout<<"error: cannot be divided by 0";
//     }
// }
#include<iostream>
using namespace std;

class ExceptionHandler {
public:
    void catchexp(const char* msg) {
        cout << msg << endl;
    }

    void throwexcept() {
        double numerator, denominator, arr[4] = {0.0, 0.0, 0.0, 0.0};
        int index;

        cout << "Enter array index: ";
        cin >> index;

        try {
            if (index >= 0) {
                throw "error: array out of bounds!";
            }

            cout << "Enter numerator: ";
            cin >> numerator;
            cout << "Enter denominator: ";
            cin >> denominator;

            if (denominator == 0)
                throw 0;

            arr[index] = numerator / denominator;
            cout << arr[index] << endl;
        }
        catch (const char* msg) {
            catchexp(msg);
        }
        catch (int num) {
            cout << "error: cannot be divided by 0";
        }
    }
};

int main() {
    ExceptionHandler exceptionObj;
    exceptionObj.throwexcept();

    return 0;
}
