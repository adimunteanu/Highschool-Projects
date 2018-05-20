#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("input.txt");

int eratos[20001];
int n, a[100001];
long long perechi, rec[100001];

void eratostene()
{
    eratos[1] = 1;
    for(int i = 2; i * i <= 20000; i++)
    {
        if(!eratos[i])
            for(int j = 2 * i; j <= 20000; j += i)
                eratos[j] = 1;
    }
}

int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> a[i];
        rec[a[i]] ++;
    }

    eratostene();

    for(int i = 1; i <= 9999; i += 2)
        for(int j = 0; j <= 10000; j += 2)
            if(!eratos[i + j] && rec[i] && rec[j])
                perechi += rec[i] * rec[j];
    cout << perechi + (rec[1] * (rec[1] - 1)) / 2 + rec[0] * rec[2];
    return 0;
}
