#include <iostream>

using namespace std;

int  n, x;

int main()
{
    cin >> n;

    int ok = 0;

    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        int div = 0;

        for(int j = 2; j <= x / 2; j++)
            if(x % j == 0)
                div++;
        if(div == 0 && x != 1)
            ok = 1;
    }

    if(ok == 1 )
        cout << "DA";
    else
        cout << "NU";


    return 0;
}
