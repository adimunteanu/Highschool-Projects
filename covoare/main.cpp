#include <fstream>

using namespace std;
int v[101][101];

int main()
{
    ifstream fin("covoare.in");
    ofstream fout("covoare.out");
    int n,m,p,i=1,j=1,k,a,b,c,x,y;
    bool ok=true;
    fin>>n>>m>>p;
    for(k=1;k<=p;k++)
    {
        fin>>a>>b>>c;
        if(j<=m && v[i][j]==0)
        {
            for(x=i;x<=i+b-1;x++)
                for(y=j;y<=j+a-1;y++)
                    v[x][y]=c;
            j=j+a;
        } else {
            if(j<=m)
            {
                ok=true;
                while(ok && j<=m)
                {
                    j++;
                    if(v[i][j]==0)
                    {
                        ok=false;
                        break;
                    }
                    if(ok==false) break;
                }
                ok=true;
                if(j<=m){
                    for(x=i;x<=i+b-1;x++)
                        for(y=j;y<=j+a-1;y++)
                            v[x][y]=c;
                    j=j+a;
                } else {
                    while(ok)
                    {
                        i++;
                        for(x=1;x<=m;x++)
                            if(v[i][x]==0){
                                ok=false;
                                j=x;
                                break;
                            }
                        if(ok==false) break;
                    }
                    ok=true;
                    for(x=i;x<=i+b-1;x++)
                        for(y=j;y<=j+a-1;y++)
                            v[x][y]=c;
                    j=j+a;
                }
            }
             else {
                while(ok)
                {
                    i++;
                    for(x=1;x<=m;x++)
                        if(v[i][x]==0){
                            ok=false;
                            j=x;
                            break;
                        }
                    if(ok==false) break;
                }
                ok=true;
                for(x=i;x<=i+b-1;x++)
                    for(y=j;y<=j+a-1;y++)
                        v[x][y]=c;
                j=j+a;
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            fout<<v[i][j]<<" ";
        fout<<'\n';
    }
    return 0;
}
