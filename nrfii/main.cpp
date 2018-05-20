#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("nrfii.in");
ofstream fout("nrfii.out");

int n, k, tata[101], fii[101], nr_max_fii;

int main()
{
    fin >> n;

    for(int i = 1; i <= n; i++)
        fin >> tata[i];

    for(int i = 1; i <= n; i++)
    {
        if(tata[i] > 0){
           fii[tata[i]]++;
        }
    }

    for(int i = 1; i <= n; i++)
        if(nr_max_fii < fii[i])
            nr_max_fii = fii[i];

    for(int i = 1; i <= n; i++)
        if(nr_max_fii == fii[i])
            fout << i << " ";
    return 0;
}
