#include <iostream>

using namespace std;
int b[101], a[101];

void shift(int n, int a[101])
{
    int l;
    l=a[1];
    int i;
    for(i=1;i<=n-1;i++) a[i]=a[i+1];
    a[n]=l;
}
int main()
{

    int i,n;
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];
    int c;
    int x=1;
    int l=n;
    while(x<=l)
    {
        c=0;
        while(c<=n-1)
        {
            shift(n,a);
            c++;
        }
        b[x]=a[x];

        n--;
        x++;

    }

    for(i=1;i<=l;i++) cout<<b[i]<<" ";
    return 0;
}
