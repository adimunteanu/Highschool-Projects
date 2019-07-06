#include <bits/stdc++.h>

using namespace std;

ifstream fin("interclasare.in");
ofstream fout("interclasare.out");

int main()
{
    int a[100001], b[100001], m, n, c[200002], p = 0;
    fin >> n;
    for(int i = 1; i <= n; i++)
        fin >> a[i];
    fin >> m;
    for(int i = 1; i <= m; i++)
        fin >> b[i];

    while(n >= 1 || m >= 1)
    {
        p++;
        if(a[n] > b[m]){
            c[p] = a[n];
            n--;
        } else {
            c[p] = b[m];
            m--;
        }
    }
    while(p){
        if(p > 9){
            for(int i = p; i > p - 10; i--)
                cout << c[i] << " ";
            cout << endl;
            p -= 10;
        } else {
            for(int i = p; i >= 1; i--)
                cout << c[i] << " ";
            p = 0;
        }
    }
    return 0;
}
