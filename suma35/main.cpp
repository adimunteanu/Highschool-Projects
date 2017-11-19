#include <fstream>
#include <iostream>

using namespace std;

int sol[335], n;
ifstream fin("suma35.in");
ofstream fout("suma35.out");

void afisare(int k)
{
    for(int i = 1; i <= k; i++)
        cout << sol[i] << " ";
    cout << "\n";
}

int ok(int k)
{
    for(int i = 1; i < k; i++)
        if(sol[i] > sol[i + 1])
            return 0;
    return 1;
}

void backtrack(int k, int s)
{
    if(s <= n){
        if(s == n)
            afisare(k - 1);
        else
            for(int i = 1; i <= 2; i++)
            {
                if(i == 1)
                    sol[k] = 3;
                else
                    sol[k] = 5;
                if(ok(k))
                    backtrack(k + 1, s + sol[k]);
            }
    }
}

int main()
{
    cin >> n;
    backtrack(1, 0);
    return 0;
}
