#include <fstream>

using namespace std;

int sol[20], n, M[20];
bool posibil = false;
ifstream fin("shuffle.in");
ofstream fout("shuffle.out");

void afisare()
{
    posibil = true;
    for(int i = 1; i <= n; i++)
        fout << sol[i] << " ";
    fout << "\n";
}

int ok(int k)
{
    int i;
    for(i = 1; i <= n; i++)
        if(sol[k] == M[i])
            break;
    if(k > 1)
        if((sol[k - 1] == M[i - 1]) || (sol[k - 1] == M[i + 1]))
            return 0;

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
    fin >> n;
    for(int i = 1; i <= n; i++)
        fin >> M[i];
    backtrack(1);
    if(!posibil)
        fout<< "nu exista";
    return 0;
}
