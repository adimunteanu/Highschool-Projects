#include <fstream>

using namespace std;

int a[1002][1002];
int dl[9]={0,-1,-1,0,1,1,1,0,-1};
int dc[9]={0,0,1,1,1,0,-1,-1,-1};
int main()
{
    ifstream fin("betasah.in");
    ofstream fout("betasah.out");
    int i,j,n,d,k,v[3][102],max,x,alb,y,z,poz;
    fin>>n>>d>>k;
    for(x=1;x<=d;x++)
    {
        fin>>i>>j;
        a[i][j]=1;
        v[1][x]=i;
        v[2][x]=j;
    }
    for(x=1;x<=k;x++)
    {
        fin>>i>>j;
        a[i][j]=2;
    }
    for(i=0;i<=n;i++)
        a[i][0]=2;
    for(j=0;j<=n+1;j++)
        a[n+1][j]=2;
    max=0;
    for(i=1;i<=n;i++)
    {
        alb=0;
        for(j=1;j<=i;j++)
        {
            if(a[i][j]==0||a[i][j]==1)
                alb++;
        }
        if(alb>max) max=alb;
    }
    fout<<max<<'\n';
    poz=0;
    for(x=1;x<=d;x++)
    {
        i=v[1][x];
        j=v[2][x];
        for(k=1;k<=8;k++)
        {
            y=dl[k];
            z=dc[k];
            while((a[i+y][j+z]==0 || a[i+y][j+z]==3) && (i+y>=j+z))
            {
                a[i+y][j+z]=3;
                y+=dl[k];
                z+=dc[k];
            }
        }
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=i;j++)
            if(a[i][j]==3) poz++;
    fout<<poz;
    return 0;
}
