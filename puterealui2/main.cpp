#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if((n & (n - 1)) == 0)
        cout << "DA";
    else
        cout << "NU";
    return 0;
}
