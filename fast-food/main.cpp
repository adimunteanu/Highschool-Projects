#include <iostream>
#include <fstream>

using namespace std;

int n, t1, t2, x, y, v[10001], minn = 10001, maxx;

int main()
{
    ifstream fin("in.txt");

    fin >> n;

    for(int i = 1; i <= n; i++){
        fin >> x >> y;
        if(minn > x) minn = x;
        if(maxx < y) maxx = y;

        v[x]++;
        v[y + 1]--;
    }

    int max_clienti = v[minn];

    for(int i = minn; i < maxx; i++){
        if(max_clienti < v[i])
            max_clienti = v[i];
        v[i + 1] += v[i];
    }

    cout << max_clienti;
    return 0;
}
