#include <iostream>
#include <algorithm>

using namespace std;



void citire (int &n, int a[])
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
}

bool prim(int n)
{
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    for(int i = 3; i*i <= n; i += 2)
        if(n % i == 0)
            return false;
    return true;
}

int fact_la_intai(int x, int &n)
{
    int putere = 0;
    while(n % x == 0)
    {
        putere++;
        n /= x;
    }
    return putere;
}

void afisare(int n, int a[])
{
    for(int i = 1; i <= n; i++)
        if(a[i + 1] != a[i])
            cout << a[i] << " ";
    if(n == 0)
        cout << "Sirul Y este vid.";
}

int main()
{
    int n, a[501], y[500], contor_y = 0;
    citire(n, a);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 2; j <= a[i]; j++)
        {
            if(prim(j) && (a[i] % j == 0)){
                int putere = fact_la_intai(j, a[i]);

                if(putere == 1){
                    contor_y ++;
                    y[contor_y] = j;
                }
            }
        }
    }
    sort(y + 1, y+ contor_y + 1);

    afisare(contor_y, y);
    return 0;
}
