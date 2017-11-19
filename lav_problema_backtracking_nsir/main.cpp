#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

ifstream fin("nsir.in");
ofstream fout("nsir.out");

float sol[75];
bool nothing_written_to_file = true;
int n;

void afisare(int k)
{
    float s = 0; float iv;

    for(int i = 1; i < k; i++)
    {
        iv = 1.0 / sol[i];
        s = s + iv;
    }
    float dumb_cunt = 1.0 / 100000;
    if(((s - 1) < dumb_cunt) && ((1 - s) < dumb_cunt))
    {
        nothing_written_to_file = false;
        for(int i = 1; i < k; i++)
            fout << sol[i] << " ";
        fout << "\n";
    }
}

void citeste()
{
    fin >> n;
}


void backtracking (int k, int sum)
{
    if(sum == n)
        afisare(k);
    else
        for(int i = sol[k - 1]; sum + i <= n; i++)
        {
            sol[k] = i;
            backtracking(k + 1, sum + i);
        }
}

int main()
{
    citeste();
    sol[0] = 1;
    backtracking(1, 0);
    if(nothing_written_to_file)
        fout << 0;
}
