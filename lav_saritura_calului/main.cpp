#include <iostream>
#include <fstream>

using namespace std;

int a[101][101], n, m, dl[8]={-2,-1,1,2,2,1,-1,-2}, dc[8]={1,2,2,1,-1,-2,-2,-1};
int ok = 0;


void afisare()
{
    if(ok == 0)
    {
        int i,j;
        for(i=1; i<=n; i++)
        {
            for(j = 1; j <= m; j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    ok = 1;
}



void backk(int x, int y, int pas)
{
    if(pas == m * n + 1)
        afisare();
    else
    {
        for(int i = 0; i < 8; i++)
        {
            if(!ok){
                int xx = x + dl[i];
                int yy = y + dc[i];
                if(xx <= n + 1 and xx >= 0 and yy <= m + 1 and yy >= 0)
                {
                    if(a[xx][yy] == 0)
                    {
                        a[xx][yy] = pas;
                        backk(xx, yy, pas+1);
                        a[xx][yy] = 0;
                    }
                }
            }
        }
    }
}
int main()
{
    cin>>n>>m;

    int l,c;

    cin>>l>>c;

    int i, j;

    i = 0;

    for(int j = 0;j <= m + 1; j++)
        a[i][j] = -1;
    j = 0;

    for(int i = 0; i <= n + 1; i++)
        a[i][j]= -1;
    i = n + 1;

    for(int j=0;j<=m+1;j++)
        a[i][j]=-1;
    j = m + 1;

    for(int i = 0; i <= n + 1; i++)
        a[i][j] = -1;

    a[l][c] = 1;

    backk(l, c, 2);

    return 0;
}
