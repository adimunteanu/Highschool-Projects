#include <iostream>

using namespace std;

int n;

bool pow_of_2(int x)
{
    while(x % 2 == 0)
        x = x / 2;
    if(x == 1)
        return true;
    else
        return false;
}

void putere(int n)
{
    int x;
    for(x = n; x >=1; x--)
    {
        if(pow_of_2(x))
            break;
    }
    if(x!=n){
        putere(n-x);
    }
    cout << x << " ";
}


int main()
{
    cin >> n;
    putere(n);

    return 0;
}
