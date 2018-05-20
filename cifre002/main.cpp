#include <fstream>
#include <iostream>

using namespace std;

int n, nrCifre, numere, pare;


int main()
{
    cin >> n;
    while(n){
        nrCifre++;
        if((n % 10) % 2 == 0)
            pare++;
        n /= 10;
    }
    numere = 1;
    for(int i = 1; i <= nrCifre - 1; i++)
        numere *= i;
    numere *= pare;
    cout << numere;
    return 0;
}
