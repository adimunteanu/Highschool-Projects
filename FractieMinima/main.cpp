#include <bits/stdc++.h>

using namespace std;

int cmmdc(int a, int b)
{
    while(b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main()
{
    int n, v[1001], minA = 2000000000, minB = 2000000000;
    float minF = 1.0;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    sort(v + 1, v + n + 1);
    for(int i = 1; i < n; i++)
        for(int j = i + 1; j <= n; j++)
        {
            float a = v[i] / cmmdc(v[i], v[j]);
            float b = v[j] / cmmdc(v[i], v[j]);
            if(a / b < minF){
                minF = a / b;
                minA = a;
                minB = b;
            }
        }
    cout << minA << "/" << minB;
    return 0;
}
