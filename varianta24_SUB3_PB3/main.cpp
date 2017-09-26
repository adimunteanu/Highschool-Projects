#include <iostream>
#include <iomanip>

using namespace std;

int a[100];

void p(int x[], int n, int &mini, int &maxi, int &sum)
{
    mini = x[1];
    maxi = x[1];
    sum = 0;
    for(int i = 1; i <= n; i++){
        if(mini > x[i])
            mini = x[i];
        if(maxi < x[i])
            maxi = x[i];
        sum += x[i];
    }
}

int main()
{
    int n, mini, maxi, sum;
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    p(a, n, mini, maxi, sum);

    float x = sum - mini - maxi;
    x /= n - 2;

    cout.precision(4);
    cout << x ;
    return 0;
}
