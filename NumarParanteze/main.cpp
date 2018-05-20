#include <iostream>

using namespace std;

int sol[2001], n, nrSol;

void afisare()
{
    /*for(int i = 1; i <= n; i++)
        if(sol[i] == 1)
            cout << "(";
        else
            cout << ")";
    cout << "\n"; */
    nrSol++;
}

int ok(int k)
{
    int par_st = 0,  par_dr = 0;

    for(int i = 1; i <= k ; i++)
        if(sol[i] == 1)
            par_st ++;
        else
            par_dr ++;
    if(par_st > n / 2 || par_dr > n / 2 || par_dr > par_st)
        return 0;
    return 1;
}

void backtrack(int k)
{
    if(k == n + 1)
        afisare();
    else
        for(int i = 1; i <= 2; i++)
        {
            sol[k] = i;
            if(ok(k))
                backtrack(k + 1);
        }
}

int main()
{
    cin >> n;
    n *= 2;
    backtrack(1);
    cout << nrSol;
    return 0;
}
