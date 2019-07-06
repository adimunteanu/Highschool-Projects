#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double d1, d2;
    cin >> d1 >> d2;
    cout << 4 * sqrt((d1 * d1) / 4 + (d2 * d2) / 4) << " " << (d1 * d2) / 2;
    return 0;
}
