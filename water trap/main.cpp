#include <iostream>

using namespace std;

int  a[100000], b[100000];

int main()
{
    int n, water = 0;
    cin >>n;
    for(int i = 1; i <=n; i++)
        cin>> a[i];

    int max_h = a[1];

    for(int i = 2; i <=n; i++)
        if(max_h < a[i])
            max_h = a[i];
    for(int i = 1; i <= n; i++)
    {
        int max_st = -1;
        int max_dr = -1;
        while(x >= 1 && y<= n)
    }

    cout << water;
    return 0;
}
