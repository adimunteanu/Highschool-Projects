#include <iostream>
#include <fstream>

using namespace std;

ofstream fout ("palindrom_ciclic.out");
ifstream fin ("palindrom_ciclic.in");

int a[1001];

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

bool palindrom (int n, int a[])
{
    for(int i = 1; i <= n / 2; i++)
        if(a[i] != a[n - i + 1])
            return false;
    return true;
}

void afisare(bool pal, int perms)
{
    if(pal)
        fout << "DA " << perms;
    else
        fout << "NU";
}

int main()
{
    int n;
    citire(n, a);
    for(int i = 0; i < n - 1; i++)
    {
        bool pal = palindrom(n, a);
        if(pal){
            afisare(pal, i);
            return 0;
        }
        else
            permutare(n, a);
    }
    afisare(false, n);
    return 0;
}
