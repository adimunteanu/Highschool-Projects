#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("izolate.in");
ofstream fout("izolate.out");

int a[101][101], n, x, y, mem[101], i_mem = 0;

int main()
{
    fin >> n;
    while(!fin.eof())
    {
        fin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }

    for(int i = 1; i <= n; i++){
        bool is_isolated = true;
        for(int j = 1; j <= n; j++)
            if(a[i][j] == 1){
                is_isolated = false;
            }
        if(is_isolated){
            i_mem++;
            mem[i_mem] = i;
        }
    }

    fout << i_mem << " ";
    for(int i = 1; i <= i_mem; i++)
    {
        fout << mem[i] << " ";
    }
    return 0;
}
