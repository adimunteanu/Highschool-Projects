#include <iostream>

using namespace std;

int n, m, x[100];

void afisare ()
{
    int i;
    for (i=1; i<=n; i++)
    {
        cout<<x[i]<<" ";
    }
    cout<<endl;
}

int validare (int i)
{
    if (i==1)
        return 1;
    if (i>1)
    {
        if (x[i]-x[i-1]>=2)
            return 1;
        else if (x[i-1]-x[i]>=2)
            return 1;
        else return 0;
    }
}

void BK (int i)
{
    int j;
    for (j=1; j<=n; j++)
    {
        x[i]=j;
        if (validare(i)==1)
        {
            if (i==m)
                afisare();
            else BK(i+1);
        }
}
}

int main ()
{
    cin>>n>>m;
    BK(1);
    return 0;
}
