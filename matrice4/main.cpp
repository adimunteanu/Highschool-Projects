#include <fstream>
#include <algorithm>

using namespace std;

int a[51][51];

int main()
{
    ifstream fin("matrice4.in");
    ofstream fout("matrice4.out");
    int n,m,j,i,k,y,winners[2510],rounds=0,x,z;
    bool ok=true,NotEmpty;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            fin>>a[i][j];
    while(ok){
        rounds++;
        NotEmpty=false;
        y=0;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                if(a[i][j]!=0)
                {
                    NotEmpty=true;
                    k=0;
                    for(x=2;x<=a[i][j]/2;x++)
                        if(a[i][j]%x==0) k++;
                    if(a[i][j]==1) a[i][j]++;
                    else
                        if(k==0){
                            y++;
                            z=y;
                            winners[y]=a[i][j];
                            a[i][j]=0;
                        } else a[i][j]++;
                }
            }
        if(NotEmpty==false) break;
    }
    fout<<rounds-1<<" "<<z<<endl;
    sort(winners+1,winners+z+1);
    for(i=1;i<=z;i++)
        fout<<winners[i]<<" ";
    return 0;
}
