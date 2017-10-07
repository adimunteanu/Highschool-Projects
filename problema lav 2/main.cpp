#include <iostream>

using namespace std;
int permutare(int n, int a[])
{
    int v[101];
    int i;
    for(i=0;i<=n;i++) v[i]=0;
    int u; int l=1;
    for(i=0;i<=n-1;i++)
    {
        u=a[i];
        if(a[i]==i+1) l=0;
        v[u]++;
    }
    i=0; int ok=1;
    while(i<=n-1)
    {
        if(v[a[i]]!=1) ok=0;

        i++;
    }
    if(ok==0 or l==0) return 0;
    else return 1;
}
int main()
{
    int i,a[101],n;
    cin>>n;
    for(i=0;i<=n-1;i++) cin>>a[i];
    int t;
    t=permutare(n,a);
    cout<<t;
    return 0;
}
