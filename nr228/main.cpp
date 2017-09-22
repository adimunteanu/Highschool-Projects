#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n,m,i,j,a[15][15],k;
    ifstream fin("nr228.in");
    fin>>n>>m;
    for(i=1;i<=n;i++)
        if(i%2==1)
        {
            k=(i-1)*m+1;
            for(j=1;j<=m;j++)
            {
                a[i][j]=k;
                k++;
            }
        }
        else
        {
            k=(i-1)*m+1;
            for(j=m;j>=1;j--)
            {
                a[i][j]=k;
                k++;
            }
        }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
