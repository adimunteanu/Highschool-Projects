#include <iostream>
int n,m,v[100];
int validare(int k);
int solutie (int k);
void afisare (int k);
void BK(int k);

using namespace std;

int main()
{
    cin>>n>>m;
    BK(1);
    return 0;
}

void BK(int k)
{
    int i;
    for (i=1;i<=m;i++)
    {
        v[k]=i;
        if (validare(k)==1)
        {
            if (solutie(k)==1) {
                afisare(k);
            }
            else BK(k+1);
        }
    }
}
int validare(int k)
{
    int i;
    for (i=0;i<=n-1;i++)
    {
        if ((v[i]!=v[i-1]-2) && (v[i]!=v[i-1]+2) ) return 0;
    }
    return 1;
}
int solutie (int k)
{
    if (k==m) return 1;
    else return 0;
}
void afisare (int k)
{
    int i;
    for (i=1;i<=k;i++)
    {
        cout<<v[i]<<" ";
        cout<<endl;
    }
}
