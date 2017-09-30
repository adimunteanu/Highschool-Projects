#include <iostream>
#include <algorithm>

using namespace std;

int a[4],b[4];

int verif(int a, int b, int c)
{
    if((a + b > c) && (a + c > b) && (b + c > a))
        return 1;
    return 0;
}

int main()
{
    bool ok = true;
    for(int i = 1; i <= 3; i++)
        cin >> a[i];
    for(int i = 1; i <= 3; i++)
        cin >> b[i];

    if((verif(a[1], a[2], a[3]) == 0) || (verif(b[1], b[2], b[3]) == 0))
        cout << "nu";
    else {
        sort(a + 1, a + 4);
        sort(b + 1, b + 4);
        for(int i = 1; i <= 3; i++)
            if(a[i] != b[i]){
                ok = false;
                break;
            }
        if(ok)
            cout << "congruente";
        else
            cout << "necongruente";
    }

    return 0;
}
