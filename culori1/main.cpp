#include <fstream>

#include <cstring>

using namespace std;
int b[52][52],c[52][52];
int main()
{
    ifstream fin("culori1.in");
    ofstream fout("culori1.out");
    int n,m,t,i,j,k;
    char a[52][52];
    fin>>n>>m>>t;
    fin.get();
    for(i=1;i<=n;i++)
        fin.getline(a[i],52);
    for(i=1;i<=n;i++)
        for(j=0;j<m;j++)
            if(a[i][j]=='r')
                b[i][j+1]++;
    for(k=1;k<=t;k++)
    {
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                c[i][j]=b[i][j];
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                c[i][j]=b[i-1][j-1]+b[i-1][j]+b[i-1][j+1]+b[i][j-1]+b[i][j+1]+b[i+1][j-1]+b[i+1][j]+b[i+1][j+1];
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                if( (i==1 && j==1) ||
                    (i==1 && j==m) ||
                    (i==n && j==1) ||
                    (i==n && j==m))

                    if(c[i][j]>1)
                        b[i][j]=1;
                    else
                        b[i][j]=0;
                else if( (i==1 && (j!=1 || j!=m)) ||
                         (i==n && (j!=1 || j!=m)) ||
                         (j==1 && (i!=1 || i!=n)) ||
                         (j==m && (i!=1 || i!=n)))
                        if(c[i][j]>2)
                            b[i][j]=1;
                        else
                            b[i][j]=0;
                     else
                        if(c[i][j]>4)
                            b[i][j]=1;
                        else if(c[i][j]<4)
                                 b[i][j]=0;
            }
    }
    for(i=1;i<=n;i++){
        for(j=0;j<m;j++)
            if(b[i][j+1]==1){
                a[i][j]='r';
                fout<<a[i][j];
            }
            else{
                a[i][j]='a';
                fout<<a[i][j];
            }
        fout<<endl;
    }
    return 0;
}
