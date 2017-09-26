#include <iostream>
#include <algorithm>

using namespace std;

int a[100];

void shift(int a[], int n)
{
    int aux = a[1];

    for(int i = 1; i < n; i++)
        a[i] = a[i+1];

    a[n] = aux;
}

int main()
{
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = 1; i <= n; i++){
        shift(a, n);
        swap(a[1], a[n]);
    }

    for(int i = 1; i <= n; i++)
        cout << a[i] << " ";

    return 0;
}
