#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("protest.in");
ofstream fout("protest.out");

int viz[50001], scandal[1001];
short int a[10001][10001];
int n, k, nrFriends = -1;

int isScandalagiu(int x)
{
    for(int i = 1; i <= k; i++)
        if(x == scandal[i])
            return 1;
    return 0;
}

void dfs(int x)
{
    viz[x] = 1;
    nrFriends++;
    for(int i = 1; i <= n; i++)
        if(viz[i] == 0 && a[x][i] == 1)
            dfs(i);
}

int main()
{
    fin >> n >> k;
    for(int i = 1; i <= k; i++)
        fin >> scandal[i];
    while(!fin.eof()){
        int x, y;
        fin >> x >> y;
        if(!isScandalagiu(y))
            a[x][y] = 1;
    }

    dfs(1);

    cout << nrFriends;
    return 0;
}
