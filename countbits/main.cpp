#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("countbits.in");
ofstream fout("countbits.out");

int n, a, b, c, d, e;
long long f1, f2, f3; //f3 e elementul curent, f2 e elementul precedent, iar f1 il preceda pe f2
long long totalBits = 0;
int v[32769]; //Vector de frecventa care numara cati de 1 are fiecare numar de la 1 la 2^15 in scrierea in baza 2


int returnBitsForPrecalc(int x)
{
    int digits = 0;
    while(x){
        if(x % 2 == 1)
            digits++;
        x /= 2;
    }
    return digits;
}

void preCalcDigits1To32768()
{
    for(int i = 0; i <= 32769; i++)
        v[i] = returnBitsForPrecalc(i);
}

int returnBits(int z)
{
    int digits = 0;
    int x = z / 32768;
    int y = z % 32768;
    return v[x] + v[y];
}

int main()
{
    fin >> n >> a >> b >> c >> d >> e;

    preCalcDigits1To32768();

    f1 = a;
    totalBits += returnBits(f1);

    f2 = b;
    totalBits += returnBits(f2);


    for(int i = 3; i <= n; i++){
        f3 = 1 + (f1 * c + f2 * d) % e;
        totalBits += returnBits(f3);
        f1 = f2;
        f2 = f3;
    }
    cout << totalBits;
    return 0;
}
