#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("knivel.in");
ofstream fout("knivel.out");

int n, k, tata[101], h[101], radacina;

void dfs(int k)
{
    for(int i = 1; i <= n; i++)
        if(tata[i] == k){
            h[i] = h[k] + 1;
            dfs(i);
        }
}

int main()
{
    fin >> n >> k;

    for(int i = 1; i <= n; i++){
        fin >> tata[i];
        if(tata[i] == 0)
            radacina = i;
    }

    h[radacina]++;
    dfs(radacina);

    for(int i = 1; i <= n; i++)
        if(h[i] == k)
            fout << i << " ";
    return 0;
}
