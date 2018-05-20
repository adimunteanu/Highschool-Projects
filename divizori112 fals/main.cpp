#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("divizor112.in");
ofstream fout("divizor112.out");

int a[100001], nrMultipli[100001], n, maxNrMult = 0;
bool rec[1000001];

int getMultipleNumber(int x)
{
    int nrMulti = 0;
    for(int i = x; i <= a[n]; i += x)
        if(rec[i])
            nrMulti++;
    return nrMulti;
}

int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> a[i];
        rec[a[i]] = true;
    }
    sort(a + 1, a + n + 1);

    int startIndex = 1;
    while(a[startIndex] == 1)
        startIndex++;
    for(int i = startIndex; i <= n; i++)
        nrMultipli[i] = getMultipleNumber(a[i]);
    for(int i = startIndex; i <= n; i++)
        if(nrMultipli[i] > maxNrMult)
            maxNrMult = nrMultipli[i];

    while(maxNrMult != nrMultipli[startIndex])
        startIndex++;
    fout << a[startIndex];
    return 0;
}
