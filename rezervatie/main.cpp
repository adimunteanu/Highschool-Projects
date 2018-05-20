#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

ifstream fin("rezervatie.in");
ofstream fout("rezervatie.out");

float rez[415][415];
char directions[10001];
int encircledTrees[1001];
int encircledTreesIndex = 0;

//E = 1, S = 2, V = 3, N = 4
int dlColt[5] = {0, 0, 2, 0, -2};
int dcColt[5] = {0, 2, 0, -2, 0};
int dlGard[5] = {0, 0, 1, 0, -1};
int dcGard[5] = {0, 1, 0, -1, 0};


int n, m, nrTrees;

void addToEncircledTrees(int tree)
{
    encircledTreesIndex++;
    encircledTrees[encircledTreesIndex] = -tree;
}

void fillRez(int x, int y, int pas)
{
    for(int i = 1; i <= 4; i++)
    {
        int xx = x + dlColt[i];
        int yy = y + dcColt[i];

        if(xx > 0 && yy > 0)
            if(rez[x + dlGard[i]][y + dcGard[i]] == -1 && rez[xx][yy] <= 0){
                if(rez[xx][yy] < 0)
                    addToEncircledTrees(rez[xx][yy]);
                rez[xx][yy] = pas;
                fillRez(xx, yy, pas + 1);
            }
    }
}

int main()
{
    fin >> n >> m;
    fin >> directions;
    fin >> nrTrees;
    for(int i = 1; i <= nrTrees; i++)
    {
        int x, y;
        fin >> x >> y;
        rez[2 * x][2 * y] = -i;
    }

    for(int i = 1; i <= 2 * n + 1; i++)
        for(int j = 1; j <= 2 * m + 1; j++)
            if((i + j) % 2 == 1)
                rez[i][j] = -1;

    int xx = 1, yy = 1;

    for(int i = 0; i < strlen(directions); i++)
        switch(directions[i]){
            case 'E':
                rez[xx + dlGard[1]][yy + dcGard[1]] = -1.5;
                xx += dlColt[1];
                yy += dcColt[1];
                break;
            case 'S':
                rez[xx + dlGard[2]][yy + dcGard[2]] = -1.5;
                xx += dlColt[2];
                yy += dcColt[2];
                break;
            case 'V':
                rez[xx + dlGard[3]][yy + dcGard[3]] = -1.5;
                xx += dlColt[3];
                yy += dcColt[3];
                break;
            case 'N':
                rez[xx + dlGard[4]][yy + dcGard[4]] = -1.5;
                xx += dlColt[4];
                yy += dcColt[4];
                break;
        }

    if(rez[2][2] < 0)
        addToEncircledTrees(rez[2][2]);

    rez[2][2] = 1;

    fillRez(2, 2, 2);

    sort(encircledTrees + 1, encircledTrees + encircledTreesIndex + 1);
    fout << encircledTreesIndex << endl;
    for(int i = 1; i <= encircledTreesIndex; i++)
        fout << encircledTrees[i] << " ";

    return 0;
}
