#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("twoop.in");
ofstream fout("twoop.out");

int a[100001], n, nrOp1, nrOp2, b[100002];

int main()
{
    fin >> n >> nrOp1 >> nrOp2;

    int sum = 0;

    for(int i = 0; i < n; i++){
        fin >> a[i];

        if(i == 0){
            b[i] = a[i];
            sum = a[i];
        }
        else {
            b[i] = a[i] - sum;
            sum = a[i];
        }
    }


    for(int i = 1; i <= nrOp1; i++)
    {
        int st, dr, val;
        fin >> st >> dr >> val;
        b[st] += val;
        b[dr + 1] -= val;
    }

    for(int i = 1; i <= nrOp2; i++){
        int poz;
        int aux = 0;
        fin >> poz;

        for(int j = 1; j <= poz; j++)
            aux += b[j];
        cout << aux << endl;
    }
    return 0;
}
