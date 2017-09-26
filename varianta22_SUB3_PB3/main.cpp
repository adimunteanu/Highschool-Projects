#include <iostream>

using namespace std;

int nz(int n)
{
    if(n < 5)
        return 0;
    else
        if((5 <= n) && (n < 10))
            return 1;
        else
            return 2;
}

int main()
{
    int k, i = 1;
    cin >> k;

    while(nz(i) != k)
        i++;

    cout << i;
    return 0;
}
