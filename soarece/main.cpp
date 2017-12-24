#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("soarece.in");
ofstream fout("soarece.out");

int is, js;
int a[12][12], n, m, bou = 0, ib, jb;
int dl[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};


void backtracking(int x, int y, int pas)
{
    if(x == ib && y == jb)
        bou++;
    else
        for(int i = 0; i < 4; i++)
        {
            int xx = x + dl[i];
            int yy = y + dc[i];


            if(a[xx][yy] == 0)
            {
                a[xx][yy] = pas;
                backtracking(xx, yy, pas + 1);
                a[xx][yy] = 0;
            }
        }
}

int main()
{
    fin >> n >> m;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            fin >> a[i][j];
            if(a[i][j] == 1)
                a[i][j] = -1;
        }

    for(int i = 0; i <= n + 1; i++){
        a[i][0] = -1;
        a[i][m + 1] = -1;
    }

    for(int i = 0; i <= m + 1; i++){
        a[0][i] = -1;
        a[n + 1][i] = -1;
    }



    fin >> is >> js >> ib >> jb;

    a[is][js] = 1;


    backtracking(is, js, 2);

    fout << bou;
    return 0;
}
