#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("input.txt");

char word[100];
int b[101][9], sumPart[101][9], maxEdgeOfZeros = 1, maxEdgeOfOnes = 1;

void convertBase10toBase2(int x, int i)
{
    int pow = 1;
    for(int j = 8; j >= 1; j--)
    {
        b[i][j] = x % 2;
        x /= 2;
    }
}

int main()
{
    cin.getline(word, 100);
    for(int i = 0; i < strlen(word); i++)
        convertBase10toBase2(int(word[i]), i + 1);

    int n = strlen(word);
    int m = 8;

    sumPart[1][1] = b[1][1];
    for(int i = 2; i <= n; i++)
        sumPart[i][1] = sumPart[i - 1][1] + b[i][1];
    for(int j = 2; j <= m; j++)
        sumPart[1][j] = sumPart[1][j - 1] + b[1][j];

    for(int i = 2; i <= n; i++)
        for(int j = 2; j <= m; j++)
            sumPart[i][j] = sumPart[i][j - 1] + sumPart[i - 1][j] + b[i][j] - sumPart[i - 1][j - 1];

    for(int i1 = 1; i1 < n; i1++)
        for(int j1 = 1; j1 < m; j1++)
            for(int i2 = i1 + 1; i2 <= n; i2++)
                for(int j2 = j1 + 1; j2 <= m; j2++){
                    int nrOfOnes = sumPart[i2][j2] - sumPart[i1 - 1][j2] - sumPart[i2][j1 - 1] + sumPart[i1 - 1][j1 - 1];
                    int length = i2 - i1 + 1;
                    int width = j2 - j1 + 1;
                    if(nrOfOnes == 0 && length == width && length > maxEdgeOfZeros)
                        maxEdgeOfZeros = length;
                    else
                        if(length * width == nrOfOnes && length == width && length > maxEdgeOfOnes)
                            maxEdgeOfOnes = length;
                }
    if(maxEdgeOfOnes > maxEdgeOfZeros)
        cout << maxEdgeOfOnes;
    else
        cout << maxEdgeOfZeros;
    return 0;
}
