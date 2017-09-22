#include <iostream>
#include <fstream>

using namespace std;

int a[100][100];

int main()
{
    ifstream fin("test.in");
    int n, m, i, j;

    fin >> n >> m;

    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            fin >> a[i][j];

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++) {
            a[i][j]++;
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }


    return 0;
}
