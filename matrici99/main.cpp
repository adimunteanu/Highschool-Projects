#include <iostream>

using namespace std;

int a[24][24];

int main()
{
    int i,j,n,k;
    cin>>n;
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=k;i++)
            a[i][k]=k;
        for(j=1;j<=k;j++)
            a[k][j]=k;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
