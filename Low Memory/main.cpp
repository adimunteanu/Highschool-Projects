#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("low_memory.in");
ofstream fout("low_memory.out");

void afisare(short n)
{
    if(n){
        unsigned long long x;
        fin >> x;
        afisare(n - 1);
        fout << x << " ";
    }
}

int main()
{
    short n;
    fin >> n;
    afisare(n);
    return 0;
}
