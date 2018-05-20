#include <iostream>
#include <fstream>
#include <algorithm>


using namespace std;

ifstream fin("input.txt");

int n, t, a[200001], answers[200001];
int x, y;

int bsearch1 (int p, int u, int key) {
    int m, n = u;

    while (p < u){
        m = (p + u) / 2;
        if (v[m] <= key)
            p = m + 1;
        else
            u = m;
    }

    m = (p + u) / 2;
    if (v[m] > key)
       -- m;
    return m;
}

int bsearch2 (int p, int u, int key) {
    int m;

    while (p < u) {
        m = (p + u) / 2;
        if (v[m] < key)
            p = m + 1;
        else
            u = m;
    }

    m = (p + u) / 2;
    if (v[m] < key)
       ++ m;
    return m;
}

int main()
{
    fin >> n >> t;
    for(int i = 1; i <= n; i++)
        fin >> a[i];

    sort(a + 1, a + n + 1);

    for(int i = 1; i <= t; i++)
    {
        fin >> x >> y;
        if(x > a[n] || y < a[1])
            answers[i] = 0;
        else {
            int st = bsearch1(x, y, );
            int dr =
            while(x > a[index])
                index++;
            while(a[index] <= y && index <= n){
                answers[i]++;
                index++;
            }
        }
    }

    for(int i = 1; i <= t; i++)
        cout << answers[i] << endl;
    return 0;
}
