#include <iostream>

using namespace std;

int calcSumCif(int x)
{
    int sum = 0;
    while(x)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main()
{
    int n, nr = 0, sumCif = 0;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        sumCif += calcSumCif(i);
        if(sumCif % 3 == 0)
            nr++;
    }
    cout << nr;
    return 0;
}
