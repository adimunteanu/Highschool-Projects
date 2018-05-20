#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("sudoku.in");
ofstream fout("sudoku.out");

int mat[11][11], co = 0, vi[]={0,0,0,1,1,1,2,2,2},vj[]={0,1,2,0,1,2,0,1,2};

void afisare() {
    int i,j;
    for(i=1;i<10;++i) {
        for (j=1;j<10;++j) fout << mat[i][j]<<' ';
        fout << '\n';
    }
}

int ok(int i, int j) {
    int k, ki, kj;
    for (k=1;k<10;++k) {
        if (mat[i][k] == mat[i][j] && k != j) return 0;
        if (mat[k][j] == mat[i][j] && k != i) return 0;
    }
    ki = ((i-1)/3) * 3 + 1; kj = ((j-1)/3) * 3 + 1;
    for (k=0;k<9;++k) {
        if (mat[ki+vi[k]][kj + vj[k]]==mat[i][j] && (ki + vi[k] != i || kj +vj[k] != j)) return 0;
    }
    return 1;
}

void backt(int i, int j) {
    int k, ki, kj;
    if (!co) {
        for (k=1;k<10;++k) {
            mat[i][j] = k;
            if(ok(i,j)) {
                for (ki=i;ki<10;++ki) for (kj=1;kj<10;++kj) {
                    if (mat[ki][kj]==0) {
						backt(ki,kj);
						ki = kj = 10;
						break;
					}
                    if (ki == 9 && kj == 9 && !co) afisare(), ++co;
                }
            }
            mat[i][j] = 0;
        }
    }
}

int main(){
    int i, j;
    for (i=1;i<10;++i) for(j=1;j<10;++j) fin >> mat[i][j];
    i=1;j=1;
    while (mat[i][j]!=0) {
        if(j<9) ++j;
        else ++i, j = 1;
    }
    backt(i,j);
    return 0;
}
