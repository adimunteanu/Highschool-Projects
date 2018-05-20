#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("prim013.in");
ofstream fout("prim013.out");

int a[1000001], n, nrPrime = 0, maxNum = 0;
short int eratos[10000001];

int isPrime(int x)
{
    if(x == 1) return 0;
    if(x == 2) return 1;
    if(x % 2 == 0) return 0;
    for(int i = 3; i*i <= x; i += 2)
        if(x % i == 0)
            return 0;
    return 1;
}

int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> a[i];
        if(maxNum < a[i])
            maxNum = a[i]; //Aici stochez cel mai mare numar, acesta fiind cel pana la care fac ciurul lui Eratostene
    }


    eratos[1] = 1;
    for(int i = 2; i*i <= maxNum; i++)
        if(!eratos[i]){
            int powerOfI = i * i; //Cu aceste 2 variabile tin evidenta puterilor nr prime
            int exponentOfPowerOfI = 2;

            for(int j = i*i; j <= maxNum; j += i){
                if(j == powerOfI){

                    if(isPrime(exponentOfPowerOfI + 1)){
                        eratos[j] = -1;
                        //Conventia este in felul urmator: 0 inseamna numar prim, 1 inseamna numar compus
                        //iar -1 inseamna putere a unui numar prim cu exponent cu 1 mai mic decat un numar prim
                    }
                    powerOfI *= i;
                    exponentOfPowerOfI++;
                } else {
                    if(eratos[j] != -1)
                        eratos[j] = 1;
                }
            }
        }
    for(int i = 1; i <= n; i++)
        if(eratos[a[i]] <= 0)
            nrPrime++;
    fout << nrPrime;
    return 0;
}
