#include <bits/stdc++.h>

using namespace std;

int in[11][3];
int s[4500][1000], maxx = 0;

ifstream fin("input.txt");

int countDigits(int index, int k)
{
    int nr = 1;
    while(s[index][k] == s[index][k+1]){
        nr++;
        k++;
    }
    return nr;
}

int main()
{
    for(int i = 1; i <= 10; i++)
    {
        fin >> in[i][0] >> in[i][1] >> in[i][2];
        if(maxx < in[i][0])
            maxx = in[i][0];
    }

    s[1][1] = 1;
    int l = 1, auxL = 0;

    for(int i = 2; i <= maxx; i++)
    {
        int j = 1;
        while(j <= l)
        {
            int nr = countDigits(i-1, j);
            auxL++;
            s[i][auxL] = nr;
            auxL++;
            s[i][auxL] = s[i-1][j];
            j += nr;
        }
        l = auxL;
        auxL = 0;
    }
    for(int i = 1; i <= 10; i++)
    {
        for(int j = in[i][1]; j <= in[i][1]+in[i][2]; j++)
            cout << s[in[i][0]][j];
        cout << endl;
    }
    return 0;
}
