#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("subgraf.in");
ofstream fout("subgraf.out");

int a[101][101], n, x, y, mem[101], i_mem, muchii = 0;

int prim(int x)
{
    if(x == 1) return 0;
    if(x == 2) return 1;
    if(x % 2 == 0) return 0;
    for(int i = 3; i * i <= x; i += 2)
        if(x % i == 0)
            return 0;
    return 1;
}

int main()
{
    fin >> n;
    while(!fin.eof())
    {
        fin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }

    for(int i = 1; i <= n; i++)
        if(prim(i))
            for(int j = 1; j <= n; j++)
                a[i][j] = a[j][i] = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(j > i)
                if(a[i][j] == 1)
                    muchii++;

    cout << muchii;
    return 0;
}
