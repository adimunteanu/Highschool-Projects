#include <iostream>

using namespace std;

int a[100];

void s1(int a[100], int &p, int &q)
{
    int auxP = 0, auxQ = 0;
    for(int i = p; i <= q; i++)
        if(a[i] % 2 == 0){
            auxP = i;
            break;
        }
    for(int i = q; i >= p; i--)
        if(a[i] % 2 != 0){
            auxQ = i;
            break;
        }
    if(auxP == 0)
        p = -1;
    else
        p = auxP;
    if(auxQ == 0)
        q = -1;
    else
        q = auxQ;
}

void s2(int &a, int &b)
{
    int aux = a;
    a = b;
    b = aux;
}

int main()
{
    int n;
    cin >> n;
    int p = 1, q = n;

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    while(p < q)
    {
        s1(a, p, q);
        if(p > q)
            break;
        s2(a[p], a[q]);
    }

    for(int i = 1; i <= n; i++)
        cout << a[i] << " ";

    return 0;
}
