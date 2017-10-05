#include <iostream>

using namespace std;

int nr_prim(int n)
{
    int i = n + 1;
    while(i)
    {
        if(i == 2) return 2;
        bool ok = true;
        if(i % 2 != 0)
        {
            for(int j = 3; j*j <= i; j += 2)
                if(i % j == 0)
                    ok = false;
            if(ok && (i != 1))
                return i;
            else
                i++;
        } else
            i++;
    }
}

int main()
{
    int n;
    cin >> n;
    cout << nr_prim(n);
    return 0;
}
