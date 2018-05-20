#include <iostream>
#include <iomanip>

using namespace std;

int n;
float m, k;

int main()
{
    cin >> n >> k >> m;
    cout << setprecision(n) << k/m;
    return 0;
}
