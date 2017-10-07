#include <iostream>

using namespace std;

double a[100];

int cautare(int n, double x[], double v)
{
    for(int i = 0; i < n; i++)
        if(x[i] == v)
            return i;
    return -1;
}

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << cautare(n, a, v);
    return 0;
}
