#include <fstream>
#include <algorithm>

using namespace std;

int sol[20], n, a[20];
ifstream fin("sirpie.in");
ofstream fout("sirpie.out");

int cmmdc(int a, int b)
{
    while(a != b)
    {
        if(a > b)
            a = a - b;
        else
            b = b - a;
    }
    if(a == 1)
        return 1;
    else return 0;
}

void afisare()
{
    for(int i = 1; i <= n; i++)
        fout << a[sol[i]] << " ";
    fout << "\n";
}

int ok(int k)
{
    if(k > 1)
        if(!cmmdc(a[sol[k - 1]], a[sol[k]]))
            return 0;
    for(int i = 1; i < k ; i++)
        if(a[sol[k]] == a[sol[i]])
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
    fin >> n;
    for(int i = 1; i <= n; i++)
        fin >> a[i];
    sort(a+1, a +n +1);
    backtrack(1);
    return 0;
}
