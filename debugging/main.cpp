#include <iostream>

using namespace std;

int n, s;
int a[100][100];


int main()
{
    cin >> n;

    for(int i = 1; i <= n ; i++)
        for(int j = 1; j <= n ; j++)
            a[i][j] = 1;

    return 0;
}
