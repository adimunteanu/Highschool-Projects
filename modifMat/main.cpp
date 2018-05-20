#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

ifstream fin("matrice.in");
ofstream fout("matrice.out");

int n, a[51][51], x, y, k;

int prim(int x)
{
    if(x == 2) return 1;
    if(x % 2 == 0) return 0;
    for(int i = 3; i * i <= x; i += 2)
        if(x % i == 0)
            return 0;
    return 1;
}

double nr_cif(int x)
{
    int c = 0;
    while(x){
        c++;
        x /= 10;
    }
    return c;
}

int superprim(int nr)
{
    int aux;
    double nr_cifre = nr_cif(nr);
    double putere_10 = pow(10.0, nr_cifre - 1);
    int zerouri = (int)putere_10;
    int prima_cif = (nr / zerouri) % 10;


    for(int i = 1; i <= nr_cifre; i++)
    {
        aux = nr % zerouri;
        aux = aux * 10 + prima_cif;
        if(prim(aux))
            return 1;
    }

    return 0;
}

int main()
{
    fin >> n;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            fin >> a[i][j];

    x = 2;
    y = n - 1;

    if(n % 2 == 0)
        k = n / 2 - 1;
    else
        k = n / 2;

    for(int i = 1; i <= k; i++){
        for(int j = x; j <= y; j++)
            swap(a[i][j], a[n - i + 1][j]);

        x++;
        y--;
    }

    x = 2;
    y = n - 1;

    for(int j = 1; j <= k; j++){
        for(int i = x; i <= y; i++)
            if(a[i][j] != a[i][n - j + 1] && superprim(a[i][j]) && superprim(a[i][n - j + 1]))
                swap(a[i][j], a[i][n - j + 1]);

        x++;
        y--;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}
