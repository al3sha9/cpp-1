#include<iostream>
using namespace std;
int main()
{
    int i,j,k;
    cout<<"Enter the number of columns.....\n\n";
    cin>>k;
    for(i=1;i<=k;i++)
    {
        for(j=1;j<=k;j++)
        {
                if(j<=i)
                {
                    if(i%3==0)
                    cout<<"* ";
                    else if(i%3==1)
                        cout<<"+ ";
                    else
                        cout<<"# ";
                }
                else
                cout<<" ";
        }
        cout<<endl;
    }
}