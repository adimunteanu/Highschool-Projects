#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

int sol[22], m, x, divizor[1000], c = 0;

ifstream fin("submdiv.in");
ofstream fout("submdiv.out");

void afisare(int k)
{
    for(int i = 1; i <= k; i++)
            fout << divizor[sol[i]] << " ";
    fout << "\n";
}

void backtrack(int k)
{
    if(k == m + 1)
        afisare(k - 1);
    else
        for(int i = sol[k - 1] + 1; i <= c; i++)
        {
            sol[k] = i;
            backtrack(k + 1);
        }
}

int main()
{
    fin >> x >> m;
    for(int i = 1; i <= x; i++)
        if(x % i == 0){
            c++;
            divizor[c] = i;
        }
    backtrack(1);
    return 0;
}
