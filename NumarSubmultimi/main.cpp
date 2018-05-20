#include <iostream>

using namespace std;

int n, k;

int main()
{
    cin >> n >> k;

    if(k > n)
        cout << 0;
    else {
        long long numarator = 1;
        for(int i = 1; i <= n; i++)
            numarator *= i;

        long long numitor = 1;
        for(int i = 1; i <= k; i++)
            numitor *= i;
        for(int i = 1; i <= n - k; i++)
            numitor *= i;

        cout << numarator / numitor;
    }

    return 0;
}
