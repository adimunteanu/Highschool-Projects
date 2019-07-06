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
    int a, b;
    cin >> a >> b;
    int cmmmc = a * b / cmmdc(a,b);
    cout << cmmmc/a + cmmmc/b + 1;
    return 0;
}
