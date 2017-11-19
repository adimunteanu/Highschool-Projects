#include <iostream>
#include <algorithm>

using namespace std;

int sol[22], n;
char a[] = "abcdefghijklmnopqrstuvwxyz";

void afisare()
{
    if(sol[0] == 0 && sol[n - 1] == 0){
        for(int i = 0; i < n; i++)
            cout << a[sol[i]];
        cout << "\n";
    }
}

int ok(int k)
{
    if(k > 0)
        if(abs(sol[k - 1] - sol[k]) != 1)
            return 0;
    return 1;
}

void backtrack(int k)
{
    if(k == n)
        afisare();
    else
        for(int i = 0; i <= (n + 1)/2; i++)
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
