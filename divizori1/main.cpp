#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("divizori1.in");
ofstream fout("divizori1.out");

int n, q, x;
int v[100001];


int main()
{
    fin >> n >> q;

    for(int i = 1; i <= n; i++){
        fin >> x;
        int j = 1;
        while(j * x <= 100000)
        {
            v[j*x]++;
            j++;
        }
    }

    for(int i = 1; i <= q; i++){
        fin >> x;
        fout << v[x] << endl;
    }

    return 0;
}
