#include<iostream>
using namespace std;

int main()
{
    int i,j,k;
    cout<<"Enter The number of matrics...\n\n";
    cin>>k;
    cout<<endl<<endl;
    for(i=1;i<=5*k;i++)
    {
        for(j=1;j<=5*k;j++)
        {
            if(i==1 || j==1 || j%5==0 || i%5==0)
            {
                cout<<"* ";
            }
            else if(i==5*k)
                cout<<"* ";
            else if(i<5 && i>1 || i<5*k && i>5*k-5 || j>1 && j<5 || j<5*k && j>5*k-5)
                cout<<"+ ";
            else
                cout<<"  ";
        }
        cout<<endl;
}
}
