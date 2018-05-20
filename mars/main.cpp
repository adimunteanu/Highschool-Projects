#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("in.txt");

int n, m, b[200002];

int main()
{
    cin >> n >> m;

    for(int i = 1; i <= m; i++)
    {
        int st, dr, val;
        cin >> st >> dr >> val;
        b[st] += val;
        b[dr + 1] -= val;
    }

    int element = 0;
    for(int i = 1; i <= n; i++){
        element += b[i];
        cout << element << " ";
    }
    return 0;
}
