#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("input.txt");

int n, m;


int main()
{
    cin >> m >> n;

    //Aranjamente de n luate cate m = n!/(n-m)!

    if(m > n)
        cout << 0;
    else {
        long long produs = 1;
        for(int i = n - m + 1; i <= n; i++)
            produs = (produs % 224737) * i;
        cout << produs % 224737;
    }
    return 0;
}
