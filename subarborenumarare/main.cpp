#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("subarborenumarare.in");
ofstream fout("subarborenumarare.out");

int n, k, tata[101], i_s = 0;

void dfs(int k)
{
    for(int i = 1; i <= n; i++)
        if(tata[i] == k){
            i_s++;
            dfs(i);
        }
}

int main()
{
    fin >> n >> k;

    for(int i = 1; i <= n; i++)
        fin >> tata[i];

    dfs(k);
    i_s++;

    fout << i_s;
    return 0;
}
