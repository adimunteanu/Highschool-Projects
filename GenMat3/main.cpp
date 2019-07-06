#include <iostream>

using namespace std;

int a[21][21];

int main()
{
    int n, m;
    cin >> n >> m;
    int x = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            a[i][j] = x * x;
            cout << a[i][j] << " ";
            x += 2;
        }
        cout << endl;
    }
    return 0;
}
