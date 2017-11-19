#include <iostream>

using namespace std;

int sol[20], n, m;

void afisare()
{
    int p = 0, c = 0;
    for(int i = 1; i <= n + m; i++)
            if(sol[i] == 0)
                p++;
            else
                c++;
    if((p == n) && (c == m)){
        for(int i = 1; i<= n + m; i++)
            cout<< sol[i] << " ";
        cout << "\n";
    }
}

int ok(int k)
{
    if(k > 2)
        if((sol[k - 1] == 0) && (sol[k - 2] == 1) && (sol[k] == 1))
            return 0;
    return 1;
}

void backtrack(int k)
{
    if(k == n + m + 1)
        afisare();
    else
        for(int i = 0; i <= 1; i++)
        {
            sol[k] = i;
            if(ok(k))
                backtrack(k + 1);
        }
}

int main()
{
    cin >> n;
    cin >> m;
    backtrack(1);
    return 0;
}
