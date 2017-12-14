#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

int sol[22], n, v[12];
ifstream fin("varf.in");
ofstream fout("varf.out");
bool nothing_printed = true;

void afisare(int k)
{
    int varf = 0;
    int coord_varf = 0;
    bool not_a_solution = false;

    for(int i = 1; i <= k; i++)
        if(v[sol[i]] > varf){
            varf = v[sol[i]];
            coord_varf = i;
        }
    if(coord_varf == 1)
        not_a_solution = true;
    else
        for(int i = coord_varf; i > 1; i--)
            if(v[sol[i]] < v[sol[i - 1]])
                not_a_solution = true;

    if(coord_varf == k)
        not_a_solution = true;
    else
        for(int i = coord_varf; i < k; i++)
            if(v[sol[i]] < v[sol[i + 1]])
                not_a_solution = true;

    if(!not_a_solution){
        nothing_printed = false;
        for(int i = 1; i <= k; i++)
                fout << v[sol[i]] << " ";
        fout << "\n";
    }
}

void backtrack(int k)
{
    if(k <= n)
        for(int i = sol[k - 1] + 1; i <= n; i++)
        {
            sol[k] = i;
            if(k >= 3)
                afisare(k);
            backtrack(k + 1);
        }
}

int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++)
        fin >> v[i];
    backtrack(1);
    if(nothing_printed)
        fout << 0;
    return 0;
}
