#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("bila.in");
ofstream fout("bila.out");

int a[21][21], b[21][21], n, m, istart, jstart, pas_max = 0;
int dl[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
bool found_sol = false;

void backtracking(int x, int y, int pas)
{
    if(x == 1 || x == n || y == 1 || y == m){
        if(pas_max < pas){
            pas_max = pas - 1;
            found_sol = true;
        }
    } else
        for(int i = 0; i < 4; i++)
        {
            int xx = x + dl[i];
            int yy = y + dc[i];
            if(b[xx][yy] == 0 && a[xx][yy] < a[x][y])
            {
                b[xx][yy] = pas;
                backtracking(xx, yy, pas + 1);
                b[xx][yy] = 0;
            }
        }
}

int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            fin >> a[i][j];
    fin >> istart >> jstart;

    backtracking(istart, jstart, 2);

    if(!found_sol)
        fout << 0;
    else
        fout << pas_max;
    return 0;
}
