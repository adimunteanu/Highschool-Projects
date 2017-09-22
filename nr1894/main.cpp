#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int n,x,y,a[20][20],i,j,aux;
    ifstream fin("nr1894.in");
    fin>>n;
    aux=n;
    x=1;
    y=2*n+1;
    while(x!=y)
    {
        for(i=x;i<=y;i++)
            for(j=x;j<=y;j++)
                a[i][j]=n;
        n--;
        x++;
        y--;
    }
    a[aux+1][aux+1]=0;
    for(i=1;i<=2*aux+1;i++)
    {
        for(j=1;j<=2*aux+1;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
