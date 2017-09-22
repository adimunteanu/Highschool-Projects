#include <iostream>
#include <fstream>

using namespace std;

void cut(long long &n)
{
    n /= 10;
}

int suma(long long n)
{
    int s = 0;
    while(n)
    {
        s += n % 10;
        n /= 10;
    }

    return s;
}

int main()
{
    //ifstream fin("in.txt");

    long long n;
    cin >> n;

    int zeroes = 0;
    int sum = suma(n);

    while(n)
    {
        cut(n);
        if(sum == suma(n))
            zeroes ++;
        else
            break;
        sum = suma(n);
    }

    cout << zeroes;
    return 0;
}
