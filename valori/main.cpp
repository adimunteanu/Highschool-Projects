#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("valori.in");
ofstream fout("valori.out");

int val[27];
int n, maxVal;
struct xd{
    char a[257];
    int val;
} cuv[1001];


int main()
{
    for(int i = 1; i <= 26; i++)
        fin >> val[i];
    fin >> n;
    fin.get();
    for(int i = 1; i <= n; i++){
        fin.getline(cuv[i].a, 257);
        for(int j = 0; j < strlen(cuv[i].a); j++)
        {
            if(cuv[i].a[j] >= 'a' && cuv[i].a[j] <= 'z')
                cuv[i].val += val[cuv[i].a[j] - 96];
            if(cuv[i].a[j] >= 'A' && cuv[i].a[j] <= 'Z')
                cuv[i].val -= val[cuv[i].a[j] - 64];
        }
        if(maxVal < cuv[i].val)
            maxVal = cuv[i].val;
    }
    for(int i = 1; i <= n; i++)
        if(cuv[i].val == maxVal)
            fout << cuv[i].a << endl;

    return 0;
}
