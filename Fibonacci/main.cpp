#include <iostream>

using namespace std;

int main()
{
    int n, a = 1, b = 1, c;
    cin >> n;
    if(n == 1)
    {
        cout << 1;
    } else {
        cout << a << " " << b << " ";
        for(int i = 3; i <= n; i++)
        {
            c = a + b;
            cout << c << " ";
            a = b;
            b = c;
        }
    }
    return 0;
}
