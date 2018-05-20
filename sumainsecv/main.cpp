#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("sumainsecv.in");
ofstream fout("sumainsecv.out");

int a[101], n, sum[101], desiredSum;
bool sequencyExists = false;

int main()
{
    fin >> n >> desiredSum;
    for(int i = 1; i <= n; i++){
        fin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    for(int i = 1; i < n; i++){
        for(int j = i + 1; j <= n; j++)
            if(sum[j] - sum[i] == desiredSum){
                sequencyExists = true;
                fout << i + 1 << " " << j;
                break;
            }
        if(sequencyExists)
            break;
    }
    return 0;
}
