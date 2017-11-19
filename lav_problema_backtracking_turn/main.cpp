#include <iostream>
#include <fstream>
using namespace std;

int sol_1[20],sol_2[20], n, H, a[20],nr[20];
int numar_cuburi = 0;

ifstream f("turn.in");
ofstream g("turn.out");

void afisare (int k)
{

    for(int i=1;i<k;i++)
        g<<sol_1[i]<<" ";
    g<<"\n";

}

int OK(int k)
{
    if(k>1)
    {
        if(a[sol_1[k]] == a[sol_1[k-1]] or sol_2[k] > sol_2[k-1])
            return 0;
        for(int i = 1; i < k; i++)
            if(sol_1[i] == sol_1[k])
                return 0;
    }

    return 1;
}

void backtracking (int k, int s)
{
    if(s<=H)
    {
        if(s==H) {
            afisare(k);
        } else
            for(int i=1;i<=n;i++)
            {
                sol_1[k]=i;
                sol_2[k] = nr[i];
                if(OK(k)) {
                    backtracking(k+1, s + sol_2[k]);
                }
            }
    }
}
int main()
{
    f>>n>>H;
    for(int i=1;i<=n;i++)
        f>>nr[i]>>a[i];
    backtracking(1,0);

}
