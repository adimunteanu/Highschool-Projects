#include <bits/stdc++.h>

using namespace std;

int a[200001];

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; i++)
    {
        int s, d, x;
        cin >> s >> d >> x;
        a[s] += x;
        a[d + 1] -= x;
    }

    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum += a[i];
        cout << sum << " ";
    }
    return 0;
}
