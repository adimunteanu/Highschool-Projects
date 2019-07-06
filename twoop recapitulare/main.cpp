#include <bits/stdc++.h>

using namespace std;

long long a[200001], b[200001];

ifstream fin("twoop.in");
ofstream fout("twoop.out");

int main()
{
    int n, nrOp1, nrOp2;
    fin >> n >> nrOp1 >> nrOp2;

    for(int i = 1; i <= n; i++)
        fin >> b[i];

    for(int i = 1; i <= nrOp1; i++)
    {
        int s, d, x;
        fin >> s >> d >> x;
        a[s] += x;
        a[d + 1] -= x;
    }

    for(int i = 2; i <= n; i++){
        a[i] += a[i - 1];
    }

    for(int i = 1; i <= n; i++)
        b[i] += a[i];
    for(int i = 1; i <= nrOp2; i++)
    {
        int op;
        fin >> op;
        cout << b[op] << '\n';
    }
    return 0;
}
