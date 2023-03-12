#include<iostream>

using namespace std;

int main()
{
    int i,j,k;
    cout<<"Enter the number of rows....\n\n";
    cin>>k;
    for(i=1;i<=k;i++)
    {
        for(j=1;j<=k;j++)
        {
            if(i==1 || i==k)
                cout<<"* ";
           else if(i==j || i==k+1-j)
                cout<<" "<<" ";
            else
                cout<<"* ";
        }
        cout<<"\n";
    }
}