#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("in.txt");
    int n,m,k,i1,j1,i2,j2,a[110][110],C,cmax,x,i,j;
    fin>>n>>m>>k;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            fin>>a[i][j];
    cmax=0;
    for(x=1;x<=k;x++)
    {
        fin>>i1>>j1>>i2>>j2;
        C=0;
        for(i=i1;i<=i2;i++)
            for(j=j1;j<=j2;j++)
                C+=a[i][j];
        if(C>cmax) cmax=C;
    }
    cout<<cmax;
    return 0;
}
