#include <iostream>

using namespace std;

int rec[1000001];



int main()
{
    int n;
    cin >> n;
    rec[1] = 1;
    for(int i = 2; i * i<= n; i++)
        if(!rec[i])
            for(int j = 2*i; j <= n; j += i)
                rec[j] = 1;
    for(int i = 2; i <= n; i++)
        if(!rec[i])
            cout << i << " ";
    return 0;
}
