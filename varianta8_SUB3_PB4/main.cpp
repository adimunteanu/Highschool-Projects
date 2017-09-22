#include <iostream>

using namespace std;

int sum(int n)
{
    int sum = 0;
    while(n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int cut(int &n)
{
    n /= 10;
}

int main()
{
    int n, zeroes = 0;
    cin >> n;
    int suma = sum(n);

    while(n)
    {
        cut(n);
        if(suma == sum(n))
            zeroes++;
        suma = sum(n);
    }

    cout << zeroes;
    return 0;
}
