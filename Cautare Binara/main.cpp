#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("input.txt");

int a[25001], n, b[200001][2], m;

int binarySearch(int l, int r, int val)
{
    if(r >= l)
    {
        int mid = (l + r) / 2;

        if(a[mid] == val)
            return mid;

        if(a[mid] > val)
            return binarySearch(l, mid - 1, val);

        return binarySearch(mid + 1, r, val);
    }

    return -1;
}

int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++)
        fin >> a[i];
    fin >> m;
    for(int i = 1; i <= m; i++)
    {
        fin >> b[i][0];
        int result = binarySearch(1, n, b[i][0]);
        if(result > 0)
            b[i][1] = 1;
    }

    for(int i = 1; i <= m; i++)
        cout << b[i][1] << " ";
    return 0;
}
