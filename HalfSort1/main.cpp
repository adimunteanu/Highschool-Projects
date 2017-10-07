#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ofstream fout ("halfsort1.out");
ifstream fin ("halfsort1.in");

void citire (int &n, int a[])
{
    fin >> n;
    for(int i = 1; i <= n; i++)
        fin >> a[i];
}

void sortare(int x, int y, int a[], bool order)
{
    if(order)
        sort(a + x, a + y);
    else
        for(int i = x; i < y; i++)
            for(int j = i + 1; j <= y; j++)
                if(a[j] > a[i])
                    swap(a[i], a[j]);
}

void afisare(int n, int a[])
{
    for(int i = 1; i <= n; i++)
        fout << a[i] << " ";
}

int main()
{
    int n, a[101];
    citire(n, a);
    sortare(1, n / 2 + 1, a, true);
    sortare(n / 2 + 1, n, a , false);
    afisare(n, a);
    return 0;
}
