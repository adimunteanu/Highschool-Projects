#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("nr659.in");
    int n,m,a[100][100],i,j,k,s,x,mins;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            fin>>a[i][j];
    k=1;
    for(i=1;i<=n;i++)
    {
        for(k=1;k<=m;k++)
        {
            s=0;
            for(j=1;j<=m;j++)
                if(j!=k)
                    s+=a[i][j];
            if(k==1)
                mins=s;
            else
                if(s<mins)
                    mins=s;
        }
        cout<<mins<<" ";
    }
    return 0;
}
