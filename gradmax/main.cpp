#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("gradmax.in");
ofstream fout("gradmax.out");

int a[101][101], n, x, y, mem[101], i_mem, maxx = 0, nr = 0;

int main()
{
    fin >> n;
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
        if(i_mem > maxx)
            maxx = i_mem;
    }

    for(int i = 1; i <= n; i++){
        i_mem = 0;
        for(int j = 1; j <= n; j++)
            if(a[i][j] == 1){
                i_mem++;
            }
        if(i_mem == maxx)
            nr++;
    }
    cout << nr << " ";
    for(int i = 1; i <= n; i++){
        i_mem = 0;
        for(int j = 1; j <= n; j++)
            if(a[i][j] == 1){
                i_mem++;
            }
        if(i_mem == maxx)
            cout << i << " ";
    }
    return 0;
}
