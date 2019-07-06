#include <iostream>
#include <algorithm>

using namespace std;

int a[10001], prime[1000001], nr_prime = 0;
short eratos[1000001];

void eratostene(int x)
{
    eratos[0] = 0;
    eratos[1] = 1;
    for(int i = 2; i <= x; i++)
        if(eratos[i] == 0){
            nr_prime++;
            prime[nr_prime] = i;
            for(int j = 2 * i; j <= x ; j += i)
                eratos[j] = 1;
        }
}

int main()
{
    int n, maxx = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(a[i] > maxx) maxx = a[i];
    }

    eratostene(maxx);
    sort(prime + 1, prime + nr_prime + 1, greater<int>());
    int sum = 0;

    for(int i = 1; i <= n; i++)
    {
        int j = 1;
        while(a[i] % prime[j] != 0)
            j++;
        sum += prime[j];
    }

    cout << sum;
    return 0;
}
