#include <fstream>
#include <algorithm>

using namespace std;

int sol[22], n;
ifstream fin("submultimi1.in");
ofstream fout("submultimi1.out");

void afisare(int k)
{
    for(int i = 1; i <= k; i++)
            fout << sol[i] << " ";
    fout << "\n";
}

int ok(int k)
{
    for(int i = 1; i < k; i++)
        for(int j = i; j <=k ; j++)
            if(abs(sol[i] - sol[j]) == 1)
                return 0;
    return 1;
}

void backtrack(int k)
{
    if(k <= n)
        for(int i = sol[k - 1] + 1; i <= n; i++)
        {
            sol[k] = i;
            if(ok(k)){
                afisare(k);
                backtrack(k + 1);
            }
        }
}

int main()
{
    fin >> n;
    backtrack(1);
    return 0;
}
