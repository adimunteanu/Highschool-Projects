#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("regine.in");
    ofstream fout("regine.out");
    int n,m,i,j,x[501],y[501],q=0,k,p;
    long a[110][110];
    fin>>n>>m;
    for(i=1;i<=m;i++)
        fin>>x[i]>>y[i];
    for(a=1;a<=m;a++)
    {
        p=0;
        for(j=y[a];j<=n;j++)
            for(b=1;b<=m;b++)
                if(y[a]==y[b]&&a!=b&&x[a]==x[b]){
                    p++;
                    break;
                }
    }
    return 0;
}
