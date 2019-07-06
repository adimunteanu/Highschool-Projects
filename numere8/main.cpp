#include <bits/stdc++.h>

using namespace std;

ifstream fin("numere8.in");
ofstream fout("numere8.out");

int rec[10000];

int main()
{
    int x;
    while(fin >> x)
    {
        if(x < 10000)
            rec[x] = 1;
    }
    for(int i = 9999; i >= 1; i--)
        if(!rec[i])
            fout << i << " ";
    return 0;
}
