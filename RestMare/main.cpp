#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("restmare.in");
ofstream fout("restmare.out");

int main()
{
    long long n;
    cin >> n;
    if(n % 2 == 0)
        cout << (n / 2 - 1)*(n/2);
    else
        cout << (n / 2 - 1)*(n / 2) + n / 2;
    return 0;
}
