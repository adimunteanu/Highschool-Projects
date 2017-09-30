#include <iostream>

using namespace std;

int numar(int x, int y)
{
    int z = 1;
    while(z * x <= y)
        z *=x;
    return z;
}

int main()
{
    int x,y;
    cin >> y >> x;
    cout << numar(x, y);
    return 0;
}
