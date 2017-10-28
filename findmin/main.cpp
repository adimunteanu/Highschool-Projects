#include <algorithm>
#include <fstream>

using namespace std;

int a[1000001], b[1000001];

int main()
{
    ifstream fin ("findmin.in");
    ofstream fout ("findmin.out");
    int n;

    fin >> n;

    for(int i = 1; i <= n; i++)
    {
        fin >> a[i];
        b[a[i]] = i;
    }

    int mini = b[1];
    int poz_mini = 1;

    for(int i = 1; i <= n; i++)
    {
        if((i > poz_mini) && (b[i] > mini))
            a[b[i]] = mini;
        else
            a[b[i]] = -1;
        if(mini > b[i]){
            mini = b[i];
            poz_mini = i;
        }
    }

    for(int i = 1; i <= n; i++)
        fout << a[i] << " ";
    return 0;
}
