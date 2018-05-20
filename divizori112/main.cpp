#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("divizor112.in");
ofstream fout("divizor112.out");

int a[100001], prime[100001], nrMultipli[100001], n, maxNrMult = 0;
short int eratos[1000001];
bool rec[1000001];

void eratostene()
{
    eratos[1] = 1;
    for(int i = 2; i * i <= a[n]; ++i)
        if(eratos[i] <= 0)
            for(int j = 2 * i; j <= a[n]; j += i)
                eratos[j] = 1;
}

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
        eratos[a[i]] = -1;
        rec[a[i]] = 1;
    }
    sort(a + 1, a + n + 1);

    eratostene();
    int indexPrime = 0;
    for(int i = 1; i <= a[n]; i++)
        if(eratos[i] == -1){
            indexPrime++;
            prime[indexPrime] = i;
        }


    for(int i = 1; i <= indexPrime; i++)
        nrMultipli[i] = getMultipleNumber(prime[i]);
    for(int i = 1; i <= indexPrime; i++)
        if(nrMultipli[i] > maxNrMult)
            maxNrMult = nrMultipli[i];

    int startIndex = 1;
    while(maxNrMult != nrMultipli[startIndex])
        startIndex++;
    cout << prime[startIndex];
    return 0;
}
