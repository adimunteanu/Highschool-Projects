#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

int minn = 1, maxx = 0;
int sol[100001], n;
char semne[100001];
ifstream fin("compar.in");
ofstream fout("compar.out");


int main()
{
    fin.getline(semne, 100001);
    n = strlen(semne) + 1;
    maxx = n;
    cout << n << endl;
    for(int i = 0; i < n; i++)
        if(semne[i] == '>'){
            cout << maxx << " ";
            maxx--;
        } else {
            cout << minn << " ";
            minn++;
        }
    return 0;
}
