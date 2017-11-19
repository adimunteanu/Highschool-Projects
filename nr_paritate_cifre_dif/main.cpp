#include <iostream>

using namespace std;

int sol[20], n;

void afisare()
{
    for(int i = 0; i < n; i++)
        cout << sol[i];
    cout << "\n";
}

int ok(int k)
{
    if((k == 0) && (sol[k] == 0))
        return 0;
    if(k > 0)
        if(sol[k] % 2 == sol[k - 1] % 2)
            return 0;
    return 1;
}

void backtrack(int k)
{
    if(k == n)
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
    backtrack(0);
    return 0;
}
