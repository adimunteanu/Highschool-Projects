#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("subgraf1.in");
ofstream fout("subgraf1.out");

int a[101][101], n, x, y, mem[101], i_mem, muchii = 0, minn;

int main()
{
    fin >> n;
    minn = n - 1;
    while(!fin.eof())
    {
        fin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }

    for(int i = 1; i <= n; i++){
        i_mem = 0;
        for(int j = 1; j <= n; j++)
            if(a[i][j] == 1){
                i_mem++;
            }
        if(i_mem < minn)
            minn = i_mem;
    }

    for(int i = 1; i <= n; i++){
        i_mem = 0;
        for(int j = 1; j <= n; j++)
            if(a[i][j] == 1){
                i_mem++;
            }
        if(i_mem == minn)
            for(int j = 1; j <= n; j++)
                a[i][j] = a[j][i] = 0;

    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(j > i)
                if(a[i][j] == 1)
                    muchii++;

    cout << muchii;
    return 0;
}
