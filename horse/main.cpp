#include <bits/stdc++.h>

using namespace std;

ifstream fin("horse.in");
ofstream fout("horse.out");

int dl[9] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
int dc[9] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
int n, p;
int board[1000][1000];
bool isOver = false;

int countSpots(int x, int y)
{
    int spots = 0;
    for(int i = 1; i <= 8; i++)
    {
        int xx = x + dl[i];
        int yy = y + dc[i];

        if(board[xx][yy] == 0 && xx > 0 && xx < n + 1 && yy > 0 && yy < n + 1)
            spots++;
    }

    return spots;
}

void traverseMatrix(int x, int y, int pas)
{
    if(pas == p){
        fout << x << " " << y;
        isOver = true;
    } else
        if(!isOver){
            board[x][y] = pas;

            int minSpots = 20000000;
            int minX, minY;

            for(int i = 1; i <= 8; i++)
            {
                int xx = x + dl[i];
                int yy = y + dc[i];
                int nrSpots;

                if(board[xx][yy] == 0 && xx > 0 && xx < n + 1 && yy > 0 && yy < n + 1){
                    nrSpots = countSpots(xx, yy);

                    if(nrSpots < minSpots)
                    {
                        minSpots = nrSpots;
                        minX = xx;
                        minY = yy;
                    }
                }
            }

            traverseMatrix(minX, minY, pas + 1);
        }
}
int main()
{

    fin >> n >> p;

    traverseMatrix(1, 1, 1);

    n = 1;
    return 0;
}
