#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("key.in");
ofstream fout("key.out");

char codDet[3];
int valKey, conditii[4];
char cod[3];
int cerinta = 0, n, sumaReparatii = 0;

int main()
{
    fin >> cerinta;
    fin >> cod;
    fin >> n;
    for(int i = 1; i <= n; ++i)
    {
        int conditie = 0;
        fin >> codDet >> valKey;
        for(int j = 0; j < 3; j++)
            if(codDet[j] == cod[j])
                conditie++;
        conditii[conditie]++;
        sumaReparatii += (valKey / 3) * (3 - conditie);
    }
    if(cerinta == 1)
    {
        for(int i = 0; i < 4; i++)
            fout << conditii[i] << " ";
    } else {
        if(sumaReparatii == 0)
            fout << "GRATIS";
        else
            fout << sumaReparatii;
    }

    return 0;
}
