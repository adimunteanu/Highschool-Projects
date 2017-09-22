#include <iostream>
#include <fstream>

int a[24][24];

using namespace std;

int main()
{
    ifstream fin("in.txt");
    int i,j,k,n,m;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            fin>>a[i][j];
    for(k=1;k<=n/2;k++)
    {
        for(j=1;j<=m;j++)
            swap(a[k][j],a[n-k+1][j]);
    }
    return 0;
}
