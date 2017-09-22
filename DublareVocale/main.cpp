#include <iostream>
using namespace std;

int main()
{
    int a[6],n,i,j,x,k;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    cin>>k;
    for(i=1;i<=k;i++){

        x=a[n];
        for(j=n;j>1;j--){
            a[j]=a[j-1];
        }
        a[1]=x;
    }
    return 0;
}
