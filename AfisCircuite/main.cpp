#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("input.txt");

int a[101][101], n, m;

int main()
{
    fin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        fin >> x >> y;
        a[x][y] = 1;
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(a[i][j])
                for(int k = 1; k <= n; k++)
                    if(a[j][k] && a[k][i])
                        cout << i << " " << j << " " << k << endl;

    return 0;
}
