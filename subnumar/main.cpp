#include <iostream>
#include <fstream>

using namespace std;

int fqy[100], cif[20];

void spread(int n, int nr_cifre, int cif[])
{
    while(n)
    {
        cif[nr_cifre] = n % 10;
        nr_cifre--;
        n /= 10;
    }
}

int main()
{
    int x;
    ifstream fin("subnumar.in");
    ofstream fout("subnumar.out");

    while(!fin.eof())
    {
        fin >> x;
        int aux = x;
        int nr_cifre = 0;
        while(aux)
        {
            nr_cifre++;
            aux /= 10;
        }

        spread(x, nr_cifre, cif);

        for(int i = 1; i < nr_cifre; i++)
            fqy[(cif[i] * 10) + cif[i + 1]]++;
    }

    int maximum = 0;
    for(int i = 10; i <= 99; i++)
        if(maximum < fqy[i])
            maximum = fqy[i];
    for(int i = 99; i >= 10; i--)
        if(maximum == fqy[i])
            fout << i << " ";
    return 0;
}
