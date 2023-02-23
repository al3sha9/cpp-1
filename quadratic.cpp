#include<iostream>
#include<cmath>
using namespace std;
int main(){

float a, b, c, x1, x2, discriminant, realside, imaginary;
    cout << "Enter coefficients a, b and c: ";
    cin >> a >> b >> c;
    discriminant = b*b - 4*a*c;
    
        x1 = (-b + sqrt(discriminant)) / (2*a);
        x2 = (-b - sqrt(discriminant)) / (2*a);
        
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
   

    return 0;

}