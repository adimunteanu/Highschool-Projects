#include <bits/stdc++.h>

using namespace std;

ifstream fin("secventaincadrata.in");
ofstream fout("secventaincadrata.out");

int pos1[10], pos2[10];

int main()
{
    int x;
    int maxx = 0, step = 0;
    while(fin >> x){
        step ++;
        if(!pos1[x])
            pos1[x] = step;
        else
            pos2[x] = step;
    }

    for(int i = 0; i <= 9 ; i ++)
        if(pos2[i] - pos1[i] + 1 > maxx)
            maxx = pos2[i] - pos1[i] + 1;
    fout << maxx << endl;
    for(int i = 0; i <= 9 ; i ++)
        if(pos2[i] - pos1[i] + 1 == maxx)
            fout << i << " ";
    return 0;
}
