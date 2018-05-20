#include <iostream>

using namespace std;

int a, b, c, p, e;

int fetchExponent(int x)
{
    int exponent = 0;
    while(x % p == 0){
        exponent++;
        x /= p;
    }
    return exponent;
}

int main()
{
    cin >> a >> b >> c >> p;

    if(c > b){
        for(int i = c + 1; i <= a; i++)
            e += fetchExponent(i);
        for(int i = 1; i <= b; i++)
            e -= fetchExponent(i);
        cout << e;
    } else {
        for(int i = b + 1; i <= a; i++)
            e += fetchExponent(i);
        for(int i = 1; i <= c; i++)
            e -= fetchExponent(i);
        cout << e;
    }

    return 0;
}
