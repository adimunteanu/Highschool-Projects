#include <fstream>

using namespace std;

int sol[20], n;
ifstream fin("plusminus.in");
ofstream fout("plusminus.out");
bool nothing_printed = true;

void afisare()
{
    int s = 0;
    for(int i = 1; i <= n; i++)
        if(sol[i] == 1)
            s -= i * i;
        else
            s += i * i;
    if(s == n){
        nothing_printed = false;
        for(int i = 1; i <= n; i++)
            if(sol[i] == 1)
                fout << "-" << " ";
            else
                fout << "+" << " ";
        fout << "\n";
    }
}



void backtrack(int k)
{
    if(k == n + 1)
        afisare();
    else
        for(int i = 1; i <= 2; i++)
        {
            sol[k] = i;
            backtrack(k + 1);
        }
}

int main()
{
    fin >> n;
    backtrack(1);
    if(nothing_printed)
        fout << "IMPOSIBIL";
    return 0;
}
