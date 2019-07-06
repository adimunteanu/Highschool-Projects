#include <bits/stdc++.h>

using namespace std;

long long a[200001], b[200001];
ifstream fin("easyquery.in");
ofstream fout("easyquery.out");

int main()
{
    int n, t;
    fin >> n;

    for(int i = 1; i <= n; i++)
        fin >> a[i];
    fin >> t;

    for(int i = 1; i <= t; i++)
    {
        int tip, s, d, x;
        fin >> tip >> s >> d >> x;
        if(tip == 1){
            b[s] += x;
            b[d + 1] -= x;
        } else {
            b[s] -= x;
            b[d + 1] += x;
        }
    }


    for(int i = 2; i <= n; i++)
        b[i] += b[i - 1];

    for(int i = 1; i <= n; i++){
        a[i] += b[i];
        fout << a[i] << " ";
    }

    return 0;
}
