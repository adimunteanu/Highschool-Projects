#include <iostream>

using namespace std;

int a[100];

void f(int a[], int n)
{
    int mini, maxi, poz_mini, poz_maxi;

    for(int i = 1; i <= n; i++)
        if(a[i] % 2 == 0)
        {
            mini = a[i];
            poz_mini = i;
            break;
        }

    for(int i = 1; i <= n; i++)
        if(a[i] % 2 != 0)
        {
            maxi = a[i];
            poz_maxi = i;
            break;
        }

    for(int i = 1; i <= n; i++)
        if((a[i] % 2 == 0) && (a[i] < mini))
        {
            mini = a[i];
            poz_mini = i;
        }
        else
            if((a[i] % 2 != 0) && (a[i] > maxi))
            {
                maxi = a[i];
                poz_maxi = i;
            }
    swap(a[poz_maxi], a[poz_mini]);
}

int main()
{
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    f(a,n);

    for(int i = 1; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}
