#include <fstream>
#include <algorithm>

using namespace std;

int sol[22], n;
ifstream fin("submultimi.in");
ofstream fout("submultimi.out");

void afisare(int k)
{
    for(int i = 1; i <= k; i++)
            fout << sol[i] << " ";
    fout << "\n";
}

void backtrack(int k)
{
    if(k <= n)
        for(int i = sol[k - 1] + 1; i <= n; i++)
        {
            sol[k] = i;
            afisare(k);
            backtrack(k + 1);
        }
}

int main()
{
    fin >> n;
    backtrack(1);
    return 0;
}
