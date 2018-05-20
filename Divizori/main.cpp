#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("input.txt");

int a[100001], n;

int main()
{
    cin >> n;
    a[1] = n;
    int i = 1;
    int workingVal = a[1];
    while(a[i] != 1)
    {
        for(int j = 2; j * j <= n; j++)
            if(a[i] % j == 0){
                i++;
                a[i] = a[i - 1] / j;
                break;
            }
    }

    sort(a + 1, a + i + 1);

    for(int k = 1; k <= i; k++)
        cout << a[k] << " ";
    return 0;
}
