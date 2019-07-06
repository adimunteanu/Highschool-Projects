#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("palindrom.in");
ofstream fout("palindrom.out");

char a[21], t[101];
int n;

int main()
{
    fin >> n;
    fin.get();
    for(int i = 1; i <= n; i++)
    {
        fin.getline(a, 21);
        int ePalindrom = 1;
        for(int j = 0; j < strlen(a) / 2; j++)
            if(a[j] != a[strlen(a) - 1 - j]){
                ePalindrom = 0;
                break;
            }
        fout << ePalindrom << endl;
    }
    return 0;
}
