#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("input.txt");

int a[101][101], viz[101];
int n, m;


void checkRouteAndResetViz(int node)
{
    int nrNodesReached = 0;
    for(int i = 1; i <= n; i++)
        if(viz[i])
            nrNodesReached++;

    if(nrNodesReached == n)
        cout << node << " ";

    for(int i = 1; i <= n; i++)
        viz[i] = 0;
}

void dfs(int x)
{
    viz[x] = 1;
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
        checkRouteAndResetViz(i);
    }


    return 0;
}
