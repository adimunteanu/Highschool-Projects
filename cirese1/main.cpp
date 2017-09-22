#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    int n,m,k,i1,j1,i2,j2,C,cmax,x,i,j;
    int a[500][500],b[500][500];
    fin>>n>>m>>k;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            fin>>a[i][j];
    b[1][1]=a[1][1];
    for(j=2;j<=m;j++)
        b[1][j]=a[1][j]+b[1][j-1];
    for(i=2;i<=n;i++)
        b[i][1]=a[i][1]+b[i-1][1];
    for(i=2;i<=n;i++)
        for(j=2;j<=m;j++)
            b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1]+a[i][j];
    cmax=0;
    for(x=1;x<=k;x++)
    {
        fin>>i1>>j1>>i2>>j2;
        C=0;
        if(i1!=1&&j1!=1)
            C=b[i2][j2]-b[i1-1][j2]-b[i2][j1-1]+b[1][1];
        else if(i1==1&&j1!=1)
                C=b[i2][j2]-b[i2][j1-1];
             else if(i1!=1&&j1==1)
                    C=b[i2][j2]-b[i1-1][j2];
                  else
                    C=b[i2][j2];
        if(C>cmax) cmax=C;

    }
    fout<<cmax;
    return 0;
}
