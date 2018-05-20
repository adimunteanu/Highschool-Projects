#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("graf_partial_2.in");
ofstream fout("graf_partial_2.out");

int a[101][101], n, x, y, mem[101], i_mem, muchii = 0, maxx;

int main()
{
    fin >> n;
    maxx = 0;
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
            for(int j = 1; j <= n; j++)
                if(a[i][j] == 1){
                    a[i][j] = a[j][i] = 0;
                    muchii ++;
                }

    }
    cout << muchii << endl;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    return 0;
}
