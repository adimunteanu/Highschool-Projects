#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    if(n == 1)
        cout << k;
    else
        for(int i = 1; i <= n; i++)
        {
            if(i == 1)
                cout << i;
            else
                if(i != n )
                    cout << 0;
                else
                    if(k != 0)
                        cout << k - 1;
                    else
                        cout << 8;
        }
    return 0;
}
