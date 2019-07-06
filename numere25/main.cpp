#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("numere25.in");
ofstream fout("numere25.out");

int main()
{
    int n, x, y;
    fin >> n;
    fin >> x;
    bool hasNumbers = false;
    for(int i = 1; i < x; i++){
        fout << i << " ";
        hasNumbers = true;
    }
    while(fin >> y)
    {
        for(int i = x + 1; i < y; i++){
            fout << i << " ";
            hasNumbers = true;
        }
        x = y;
    }
    for(int i = y + 1; i <= n; i++){
        fout << i << " ";
        hasNumbers = true;
    }

    if(!hasNumbers)
        fout << "Nu exista";
    return 0;
}
