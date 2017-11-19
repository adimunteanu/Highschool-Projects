#include <iostream>

using namespace std;

int elimcif(int n, int c)
{
    if(n < 10)
        if(n == c)
            return 0;
        else
            return n;
    else {
        int x = elimcif(n / 10, c);
        if(n % 10 != c)
            return x * 10 + (n % 10);
        else
            return x;
    }
}

int main()
{
    int n, c;
    cin >> n >> c;
    cout << elimcif(n, c);
    return 0;
}
