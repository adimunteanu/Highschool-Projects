#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");

int a[200][200];
int output[200];
int outputLen = 0;

void addPiece(char piece)
{
    outputLen++;
    switch(piece){
        case 'A':
            output[outputLen] = 1;
            break;
        case 'B':
            output[outputLen] = 2;
            break;
        case 'C':
            output[outputLen] = 3;
            break;
    }
}

void nextPiece(char &piece)
{
    switch(piece){
        case 'A':
            piece = 'B';
            break;
        case 'B':
            piece = 'C';
            break;
        case 'C':
            piece = 'A';
            break;
    }
}

void placePieceLeft(char &piece, int &ii, int &jj)
{
    switch(piece){
        case 'A':
            a[ii][jj] = 1;
            a[ii][jj + 1] = 1;
            a[ii][jj + 2] = 1;
            jj += 3;
            break;
        case 'B':
            a[ii][jj] = 2;
            a[ii + 1][jj] = 2;
            a[ii + 1][jj + 1] = 2;
            ii++;
            jj += 2;
            break;
        case 'C':
            a[ii][jj] = 3;
            a[ii][jj + 1] = 3;
            a[ii + 1][jj + 1] = 3;
            a[ii + 2][jj + 1] = 3;
            ii += 2;
            jj += 2;
            break;
    }
    addPiece(piece);
    nextPiece(piece);
}

void placePieceRight(char &piece, int &ii, int &jj)
{
    switch(piece){
        case 'A':
            a[ii][jj] = 1;
            a[ii][jj - 1] = 1;
            a[ii][jj - 2] = 1;
            jj -= 3;
            break;
        case 'B':
            a[ii][jj] = 2;
            a[ii][jj - 1] = 2;
            a[ii - 1][jj - 1] = 2;
            ii--;
            jj -= 2;
            break;
        case 'C':
            a[ii][jj] = 3;
            a[ii - 1][jj] = 3;
            a[ii - 2][jj] = 3;
            a[ii - 2][jj - 1] = 3;
            ii -= 2;
            jj -= 2;
            break;
    }
    addPiece(piece);
    nextPiece(piece);
}

bool itFitsLeft(char piece, int x, int y, int lin, int col)
{
    switch(piece){
        case 'A':
            if(1 <= y + 2 && y + 2 <= col)
                if(a[x][y + 1] == 0 && a[x][y + 2] == 0)
                    return true;
            break;
        case 'B':
            if((1 <= x + 1 && x + 1 <= lin) && (1 <= y + 1 && y + 1 <= col))
                if(a[x + 1][y] == 0 && a[x + 1][y + 1] == 0)
                    return true;
            break;
        case 'C':
            if((1 <= x + 2 && x + 2 <= lin) && (1 <= y + 1 && y + 1 <= col))
                if(a[x][y + 1] == 0 && a[x + 1][y + 1] == 0 && a[x + 2][y + 1] == 0)
                    return true;
            break;
    }
    return false;
}

bool itFitsRight(char piece, int x, int y, int lin, int col)
{
    switch(piece){
        case 'A':
            if(1 <= y - 2 && y - 2 <= col)
                if(a[x][y - 1] == 0 && a[x][y - 2] == 0)
                    return true;
            break;
        case 'B':
            if((1 <= x - 1 && x - 1 <= lin) && (1 <= y - 1 && y - 1 <= col))
                if(a[x - 1][y] == 0 && a[x - 1][y - 1] == 0)
                    return true;
            break;
        case 'C':
            if((1 <= x - 2 && x - 2 <= lin) && (1 <= y - 1 && y - 1 <= col))
                if(a[x][y - 1] == 0 && a[x - 1][y] == 0 && a[x - 2][y - 1] == 0)
                    return true;
            break;
    }
    return false;
}

int main()
{
    for(int index = 1; index <= 5; index++)
    {
        int lin, col, start, n, blocked[100], numarator = 1;
        //Input
        fin >> lin >> col >> start >> n;
        for(int i = 1; i <= n; i++)
            fin >> blocked[i];

        //Array initialization
        int ii, jj;
        for(int i = 1; i <= lin; i++)
            for(int j = 1; j <= col; j++){
                for(int k = 1; k <= n; k++){
                    if(numarator == blocked[k])
                        a[i][j] = 4;
                    if(numarator == start){
                        ii = i;
                        jj = j;
                    }
                }
                numarator++;
            }

        char piece = 'A';

        if(jj == 1){
            //Left to right
            while(jj <= col)
            {
                if(itFitsLeft(piece, ii, jj, lin, col))
                    placePieceLeft(piece, ii, jj);
                else
                    nextPiece(piece);
            }
            //Output
            for(int i = 1; i <= outputLen; i++)
                cout << char(output[i] + 64);
            cout << endl;
        } else {
            //Right to left
            while(jj >= 1)
            {
                if(itFitsRight(piece, ii, jj, lin, col))
                    placePieceRight(piece, ii, jj);
                else
                    nextPiece(piece);
            }
            //Output
            for(int i = outputLen; i >= 1; i--)
                cout << char(output[i] + 64);
            cout << endl;
        }

        //Reset all globals
        for(int i = 1; i <= outputLen; i++)
            output[i] = 0;
        outputLen = 0;
        for(int i = 1; i <= lin; i++)
            for(int j = 1; j <= col; j++)
                a[i][j] = 0;
    }
    return 0;
}
