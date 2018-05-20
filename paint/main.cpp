#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("paint.in");
ofstream fout("paint.out");

int n, k, m, d, l;
int zid[250001];

int main()
{
    fin >> n >> k >> m;
    for(int i = 1; i <= m; i++){
        fin >> d >> l;

        zid[d + 1]++;
        zid[d + l + 1]--;
    }

    int unpaintedSurface = 0;
    int currentSurface = 0;

    for(int i = 1; i <= n; i++){
        currentSurface += zid[i];
        if(currentSurface < k)
            unpaintedSurface++;
    }
    cout << unpaintedSurface;
    return 0;
}
