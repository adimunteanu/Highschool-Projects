#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("schimb.in");
ofstream fout("schimb.out");

int n, k, p;
char a[502];

int main()
{
    fin >> n >> k >> p;
    fin.get();
    for(int i = 1; i <= n; i++){
        fin.getline(a, 502);
        if(strlen(a) < k){
            for(int j = strlen(a) - 1; j >= 0; j--)
                fout << a[j];
            fout << endl;
        } else {
            a[k - 1] = char(p + 96);
            fout << a << endl;
        }
    }
    return 0;
}
