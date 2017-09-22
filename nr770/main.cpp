#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("nr770.in");
    int n,m,i,j,a[100][100],aux[100];
    fin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            fin>>a[i][j];
    for(i=1;i<=n;i++)
        aux[i]=a[i][1];
    for(j=2;j<=m;j++)
        for(i=1;i<=n;i++)
            a[i][j-1]=a[i][j];
    for(i=1;i<=n;i++)
        a[i][m]=aux[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
