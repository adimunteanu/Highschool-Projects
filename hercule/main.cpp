#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("hercule.in");
ofstream fout("hercule.out");

int a[12][12], b[12][12], n, m, ways = 0;
int dl[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};


void print()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            fout << b[i][j] << " ";
        fout << endl;
    }
    fout << endl;
}

void backtracking(int x, int y, int pas)
{
    if(x == n && y == m)
        ways++;
    else
        for(int i = 0; i < 4; i++)
        {
            int xx = x + dl[i];
            int yy = y + dc[i];


            if(a[xx][yy] > 1 && b[xx][yy] == 0)
            {
                b[xx][yy] = pas;
                for(int i = 1; i <= n; i++)
                    for(int j = 1; j <= m; j++)
                        a[i][j]--;
                backtracking(xx, yy, pas + 1);
                b[xx][yy] = 0;
                for(int i = 1; i <= n; i++)
                    for(int j = 1; j <= m; j++)
                        a[i][j]++;
            }
        }
}

int main()
{
    fin >> n >> m;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            fin >> a[i][j];

    for(int i = 0; i <= n + 1; i++){
        b[i][0] = -1;
        b[i][m + 1] = -1;
    }

    for(int i = 0; i <= m + 1; i++){
        b[0][i] = -1;
        b[n + 1][i] = -1;
    }

    b[1][1] = 1;


    backtracking(1, 1, 2);

    fout << ways;
    return 0;
}
