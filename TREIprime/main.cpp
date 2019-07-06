#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    bool notFound = true;
    int p = 1;
    while(notFound)
    {
        p++;
        if(n % p == 0){
            notFound = false;
        }
    }
    int sum = n / p - (m / (p - 1)) + 1;
    int prod = n / p;
    int delta = sum*sum - 4*prod;
    cout << p << " " << (sum - sqrt(delta))/2 << " " << (sum + sqrt(delta))/2;
    return 0;
}
