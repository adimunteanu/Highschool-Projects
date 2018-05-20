#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("detdrum2.in");
ofstream fout("detdrum2.out");

int tata[101], n, p, q;
int pPath[101], qPath[101], index = 0;

void dfs(int x, int arr[])
{
    if(x != 0){
        index++;
        arr[index] = x;
        dfs(tata[x], arr);
    }
}

int main()
{
    fin >> n >> p >> q;
    for(int i = 1; i <= n; i++)
        fin >> tata[i];

    dfs(p, pPath);
    int pIndex = index;
    index = 0;
    dfs(q, qPath);
    int qIndex = index;

    for(int i = 1; i <= pIndex / 2; i++)
        swap(pPath[i], pPath[pIndex - i + 1]);

    for(int i = 1; i <= qIndex / 2; i++)
        swap(qPath[i], qPath[qIndex - i + 1]);

    index = 1;
    while(pPath[index] == qPath[index])
        index++;
    index--;

    for(int i = pIndex; i >= index; i--)
        fout << pPath[i] << " ";
    for(int i = index + 1; i <= qIndex; i++)
        fout << qPath[i] << " ";
    return 0;
}
