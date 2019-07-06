#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("interclasare2.in");
ofstream fout("interclasare2.out");

int main()
{
    int a[100001], b[100001], c[200002], index = 0, n, m;
    fin >> n;
    for(int i = 1; i <= n; i++)
        fin >> a[i];
    fin >> m;
    for(int i = 1; i <= m; i++)
        fin >> b[i];
    int i = 1, j = 1;
    while(i <= n && j <= m)
    {
        if(a[i] > b[j]){
            j++;
        } else {
            if(a[i] < b[j]){
                i++;
            } else {
                index++;
                c[index] = a[i];
                i++; j++;
            }
        }
    }


    int nrOut = index;
    int startIndex = 1;
    while(nrOut / 10 != 0){
        for(int i = startIndex, j = 1; i <= index, j <= 10; i++, j++)
            fout << c[i] << " ";
        fout << endl;
        nrOut -= 10;
        startIndex += 10;
    }
    for(int i = startIndex; i <= index; i++)
        fout << c[i] << " ";
    return 0;
}
