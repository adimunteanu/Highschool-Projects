#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("in.txt");
char a[41];
int perechi[26][26];

int main()
{
    while(cin >> a){
        for(int i = 0; i < strlen(a) - 1; i++)
            if(strchr("aeiou", a[i]) != NULL)
                if(strchr("aeiou", a[i + 1]) != NULL)
                    perechi[a[i] - 97][a[i + 1] - 97]++;
    }

    int maxx = 0;
    for(int i = 0; i <= 25; i++)
        for(int j  = 0; j <= 25; j++)
            if(perechi[i][j] > maxx)
                maxx = perechi[i][j];
    if(maxx == 0)
        cout << "NU";
    else {
        int ii = 0; int jj = 0;
        for(int i = 0; i <= 25; i++){
            bool shouldBreak = false;
            for(int j = 0; j <= 25; j++)
                if(perechi[i][j] == maxx){
                    ii = i;
                    jj = j;
                    cout << char(i + 97) << char(j + 97);
                    shouldBreak = true;
                    break;
                }
            if(shouldBreak)
                break;
        }
        for(int i = 0; i <= 25; i++)
            for(int j = 0; j <= 25; j++)
                if(perechi[i][j] == maxx && (i != ii || j != jj))
                    cout << " " << char(i + 97) << char(j + 97);
    }
    return 0;
}
