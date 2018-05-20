#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("componenteconexe1.in");
ofstream fout("componenteconexe1.out");

int n, a[100][100];

int main()
{
    fin >> n;

    while(!fin.eof())
    {
        int x, y;
        fin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }

    for(int i = 1; i <= n; i++)
        if
    return 0;
}
