#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("input.txt");

int a[101][101], viz[101], rec[101];
int n, m;

void resetViz()
{
    for(int i = 1; i <= n; i++)
        viz[i] = 0;
}

void dfs(int x)
{
    viz[x] = 1;
    rec[x]++;
    for(int i = 1; i <= n; i++)
        if(viz[i] == 0 && a[x][i] == 1)
            dfs(i);
}

int main()
{
    fin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        fin >> x >> y;
        a[x][y] = 1;
    }

    for(int i = 1; i <= n; i++){
        dfs(i);
        resetViz();
    }

    int i = 1;
    while(rec[i] != n && i <= n + 1)
        i++;
    if(i == n + 2)
        cout << "NU EXISTA";
    else
        cout << i;
    return 0;
}
