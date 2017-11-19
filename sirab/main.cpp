#include <fstream>
#include <iostream>

using namespace std;

int sol[20], n, s;
ifstream fin("sirab.in");
ofstream fout("sirab.out");
bool nothing_printed = true;


void afisare(int k)
{
    nothing_printed = false;
    for(int i = 1; i <= k; i++)
        fout << sol[i] << " ";
    fout << "\n";
}

int ok(int k)
{
    for(int i = 1; i < k ; i++)
        if(sol[k] == sol[i] || sol[i] > sol[i + 1])
            return 0;
    for(int i = 1; i < k ; i++)
        for(int j = i + 1; j <= k; j++)
            if((sol[j] + sol[i]) % (sol[j]-sol[i]) != 0)
                return 0;
    return 1;
}

void backtrack(int k)
{
    if(k == n + 1)
        afisare(k - 1);
    else
        for(int i = 1; i <= s; i++)
        {
            sol[k] = i;
            if(ok(k))
                backtrack(k + 1);
        }
}

int main()
{
    fin >> s >> n;
    backtrack(1);
    if(nothing_printed)
        fout << 0;
    return 0;
}
