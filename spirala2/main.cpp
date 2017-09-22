#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("spirala2.in");
    ofstream fout("spirala2.out");
    int n,a[510][510],i,j,c,k,p,x,s,aux;
    fin>>p;
    fin>>n>>k;
    x=1;
    for(c=1;c<=n/2;c++)
    {
        for(j=c;j<=n-c+1;j++){
            a[c][j]=x;
            x++;
        }
        for(i=c;i<=n-c;i++){
            a[i+1][n-c+1]=x;
            x++;
        }
        for(j=n-c;j>=c;j--){
            a[n-c+1][j]=x;
            x++;
        }
        for(i=n-c;i>c;i--){
            a[i][c]=x;
            x++;
        }
    }
    if(n%2==1) a[n/2+1][n/2+1]=n*n;
    if(p==1){
        s=0;
        for(i=1;i<=n;i++)
            if(i!=k) s+=a[i][k]%100003;
        for(j=1;j<=n;j++)
            if(j!=k) s+=a[k][j]%100003;
        fout<<s;
    }else{
        for(x=1;x<=n;x++)
            if(x!=k){
                aux=a[x][k];
                a[x][k]=a[k][x];
                a[k][x]=aux;
            }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                fout<<a[i][j]<<" ";
            fout<<endl;
        }
    }
    return 0;
}
