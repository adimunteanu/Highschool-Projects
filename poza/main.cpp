#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("in.txt");
    int n,m,a[100][100],i,j,p,q,x,y;
    bool ok=false;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            fin>>a[i][j];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            if(a[i][j]==1){
                x=i;
                ok=true;
                break;
            }
        if(ok) break;
    }
    ok=false;
    for(j=1;j<=m;j++)
    {
        for(i=1;i<=n;i++)
            if(a[i][j]==1){
                y=j;
                ok=true;
                break;
            }
        if(ok) break;
    }
    ok=false;
    for(i=n;i>=1;i--)
    {
        for(j=m;j>=1;j--)
            if(a[i][j]==1){
                p=i;
                ok=true;
                break;
            }
        if(ok) break;
    }
    ok=false;
    for(j=m;j>=1;j--)
    {
        for(i=n;i>=1;i--)
            if(a[i][j]==1){
                q=j;
                ok=true;
                break;
            }
        if(ok) break;
    }
    cout<<p-x+1<<" "<<q-y+1<<endl;
    for(i=x;i<=p;i++){
        for(j=y;j<=q;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return x;
}
