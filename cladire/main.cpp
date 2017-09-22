#include <iostream>
#include <fstream>

using namespace std;
long long a[1000][1000];
int main()
{
    ifstream fin("cladire.in");
    ofstream fout("cladire.out");
    int n,m,k,i,j;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        a[i][1]=1;
    for(j=1;j<=m;j++)
        a[1][j]=1;
    for(i=2;i<=n;i++)
        for(j=2;j<=m;j++)
            a[i][j]=(a[i-1][j]+a[i][j-1])%9901;
    fout<<a[n][m];
    return 0;
}
