#include <fstream>
#include <iostream>

using namespace std;

int sol[20], n;
ifstream fin("permutari1.in");
ofstream fout("permutari1.out");

void afisare()
{
    for(int i = 1; i <= n; i++)
        cout << sol[i] << " ";
    cout << "\n";
}

int ok(int k)
{
    for(int i = 1; i < k ; i++)
        if(sol[k] == sol[i])
            return 0;
    return 1;
}

void backtrack(int k)
{
    if(k == n + 1)
        afisare();
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
    cin >> n;
    backtrack(1);
    return 0;
}
