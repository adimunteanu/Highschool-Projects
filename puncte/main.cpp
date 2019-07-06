#include <iostream>
#include <cmath>

using namespace std;

double a[101];
int n;
int nr;
double x, y;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        a[i] = sqrt(x * x + y * y);
    }
    double maxx = 0;
    for(int i = 1; i <= n; i++)
        if(maxx < a[i])
            maxx = a[i];
    for(int i = 1; i <= n; i++)
        if(maxx == a[i])
            nr++;
    cout << maxx << " " << nr;
    return 0;
}
