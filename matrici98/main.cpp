#include <iostream>

using namespace std;

int a[24][24];

int main()
{
    int n,i,j,k,x;
    cin>>n;
    k=0;
    x=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            a[i][j]=x;
            x+=2;
        }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
