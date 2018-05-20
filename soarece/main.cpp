#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("soarece1.in");
ofstream fout("soarece1.out");

int is, js;
int b[12][12], n, m, bou = 0, ib, jb;
char a[12][12];
bool found_sol = false;
int dl[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};


void print()
{
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            if(b[i][j] == -1)
                fout << 0 << " ";
            else
                fout << b[i][j] << " ";
        fout << endl;
    }
    found_sol = true;
}

void backtracking(int x, int y, int pas)
{
    if(x == ib && y == jb){
        if(!found_sol)
            print();
    }
    else
        for(int i = 0; i < 4; i++)
        {
            int xx = x + dl[i];
            int yy = y + dc[i];


            if(b[xx][yy] == 0)
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

    for(int i = 0; i < n; i++)
        fin >> a[i];

    for(int i = 0; i <= n + 1; i++){
        b[i][0] = -1;
        b[i][m + 1] = -1;
    }

    for(int i = 0; i <= m + 1; i++){
        b[0][i] = -1;
        b[n + 1][i] = -1;
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            switch(a[i][j]){
                case '_':
                    b[i + 1][j + 1] = 0;
                    break;
                case '#':
                    b[i + 1][j + 1] = -1;
                    break;
                case 'B':
                    b[i + 1][j + 1] = 0;
                    ib = i + 1;
                    jb = j + 1;
                    break;
                case 'S':
                    b[i + 1][j + 1] = 1;
                    is = i + 1;
                    js = j + 1;
                    break;
            }



    backtracking(is, js, 2);

    if(!found_sol)
    {
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++)
                fout << 0 << " ";
            fout << endl;
        }
    }

    return 0;
}
