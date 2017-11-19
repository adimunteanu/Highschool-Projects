#include <iostream>
#include <algorithm>

using namespace std;

int sol[22], n;

void afisare()
{
    if(sol[1] == 0 && sol[n] == 0){
        for(int i = 1; i <= n; i++)
            cout << sol[i];
        cout << "\n";
    }
}

int ok(int k)
{
    if(k > 1)
        if(abs(sol[k - 1] - sol[k]) != 1)
            return 0;
    return 1;
}

void backtrack(int k)
{
    if(k == n + 1)
        afisare();
    else
        for(int i = 0; i <= 9; i++)
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
