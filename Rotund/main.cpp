#include <iostream>
#include <fstream>

using namespace std;

ofstream fout ("rotund.out");
ifstream fin ("rotund.in");

void citire (int &n, int a[])
{
    fin >> n;
    for(int i = 1; i <= n; i++)
        fin >> a[i];
}

void permutare (int n, int a[])
{
    int aux = a[1];
    for(int i = 1; i < n; i++)
        a[i] = a[i + 1];
    a[n] = aux;
}

int formare_nr(int nr_cif, int a[])
{
    int nr = 0;
    for(int i = 1; i <= nr_cif; i++)
        nr = nr * 10 + a[i];
    return nr;
}

bool rotund(int n)
{
    int a[11];
    int aux = n;
    int nr_cif = 0;
    int k = 0;

    while(aux)
    {
        nr_cif ++;
        aux /= 10;
    }

    aux = n;
    int aux_nr_cif = nr_cif;

    while(aux)
    {
        a[nr_cif] = aux % 10;
        cout << a[nr_cif] << " ";
        nr_cif--;
        aux /= 10;
    }

    nr_cif = aux_nr_cif;

    while(k < nr_cif - 1)
    {
        permutare(nr_cif, a);
        int nr = formare_nr(nr_cif, a);

        if(nr == n)
            return true;
        else k++;
    }

    return false;
}

void afisare(int n, int a[])
{
    fout << n << '\n';
    for(int i = 1; i <= n; i++)
        fout << a[i] << " ";
}

int main()
{
    int n, a[51], nr_rot = 0, b[51];
    citire(n, a);

    for(int i = 1; i <= n; i++)
        if(rotund(a[i])){
            nr_rot++;
            b[nr_rot] = a[i];
        }
    afisare(nr_rot, b);
    return 0;
}
