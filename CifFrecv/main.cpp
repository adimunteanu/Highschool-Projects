#include <bits/stdc++.h>

using namespace std;

ifstream fin("ciffrecv.in");
ofstream fout("ciffrecv.out");

int rec[10];

int prim(int n)
{
    if(n < 2) return 0;
    if(n == 2) return 1;
    if(n % 2 == 0) return 0;
    for(int i = 3; i <= n / 2; i+=2)
        if(n % i == 0)
            return 0;
    return 1;
}

int main()
{
    int x;
    while(fin >> x)
        rec[x]++;
    for(int i = 9 ; i >= 0; i--)
        if(prim(i) && rec[i] != 0){
            cout << i << " " << rec[i];
            break;
        }

    return 0;
}
