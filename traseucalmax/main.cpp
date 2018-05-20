#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("traseucal.in");
ofstream fout("traseucal.out");

int a[101][101], b[101][101], pas_max = 0, n, m, dl[8]={-2,-1,1,2,2,1,-1,-2}, dc[8]={1,2,2,1,-1,-2,-2,-1};



void set_matrix(int pas)
{
    int i,j;
    for(i=1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            if(a[i][j] == -1)
                b[i][j] = 0;
            else
                b[i][j] = a[i][j];
        }
    }
    pas_max = pas;
}



void backk(int x, int y, int pas)
{
    if(x == n && y == m && pas > pas_max)
        set_matrix(pas);
    else
    {
        for(int i = 0; i < 8; i++)
        {
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
int main()
{
    fin>>n>>m;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            fin >> a[i][j];
            if(a[i][j] == 1)
                a[i][j] = -1;
        }

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

    a[1][1] = 1;

    backk(1, 1, 2);

    for(i=1; i<=n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            fout << b[i][j] << " ";
        }
        fout<<"\n";
    }
    return 0;
}
