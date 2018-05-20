#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("livada.in");
ofstream fout("livada.out");

int m, n, p;
int soiCurent = 0, pomiConsec = 0, maxPomiConsec = 0, pom[700001], pomPrecedent = 0, frecventaPomi[100000000];

void verificareMaximPomiConsecutivi(int &maxPomiConsec, int &pomiConsec)
{
    if(pomiConsec > maxPomiConsec)
        maxPomiConsec = pomiConsec;
}

int main()
{
    fin >> n >> m >> p;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> pom[j];
            if(pomPrecedent != 0){
                if(pomPrecedent == pom[j]){
                    frecventaPomi[pom[j]]++;
                    pomiConsec++;
                    verificareMaximPomiConsecutivi(maxPomiConsec, pomiConsec);
                    pomPrecedent = pom[j];
                }
            } else {
                frecventaPomi[pom[j]]++;
                pomPrecedent = pom[j];
                pomiConsec++;
                verificareMaximPomiConsecutivi(maxPomiConsec, pomiConsec);
            }

        }
        for(int i = 1; i <= p; i++)

        pomiConsec = 0;
    }
    return 0;
}
