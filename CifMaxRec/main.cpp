#include <iostream>

using namespace std;

int cifmax(int n)
{
    if(n == 0)
        return 0;
    else{
        int c = cifmax(n / 10) % 10;
        if(c > n % 10)
            return c;
        else
            return n % 10;
    }
}

int main()
{
    int n;
    cin >> n;
    cout << cifmax(n);
    return 0;
}
