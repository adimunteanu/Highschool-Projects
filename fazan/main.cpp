#include <fstream>
#include <cstring>

using namespace std;

int sol[20], n, m;
ifstream fin("input.txt");
ofstream fout("output.txt");

char words[16][11];


void afisare(int k)
{
    for(int i = 1; i <= k; i++)
        fout << words[sol[i]] << " ";
    fout << "\n";
}

int ok(int k)
{
    for(int i = 1; i < k ; i++)
        if(sol[k] == sol[i])
            return 0;
    if(k > 1)
        for(int j = 1; j < k; j++){
            char a1 = words[sol[j]][strlen(words[sol[j]]) - 2];
            char a2 = words[sol[j]][strlen(words[sol[j]]) - 1];
            char b1 = words[sol[j + 1]][0];
            char b2 = words[sol[j + 1]][1];
            if( a1 != b1 ||  a2 != b2)
                return 0;
        }
    return 1;
}

void backtrack(int k)
{
    if(k == m + 1)
        afisare(k - 1);
    else
        for(int i = 1; i <= n; i++)
        {
            sol[k] = i;
            if(ok(k))
                backtrack(k + 1);
        }
}

int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        fin >> words[i];
    backtrack(1);
    return 0;
}
