#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("subarbore.in");
ofstream fout("subarbore.out");

int n, k, tata[101], s[101], i_s = 0;

void dfs(int k)
{
    for(int i = 1; i <= n; i++)
        if(tata[i] == k){
            i_s++;
            s[i_s] = i;
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
    s[i_s] = k;
    sort(s + 1, s + i_s + 1);
    for(int i = 1; i <= i_s; i++)
        fout << s[i] << " ";
    return 0;
}
