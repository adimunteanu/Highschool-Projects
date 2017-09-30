#include <iostream>

using namespace std;

int verif(int a, int b, int c)
{
    if((a + b > c) && (a + c > b) && (b + c > a))
        return 1;
    return 0;
}

int main()
{
    int a, b, c, x, y, z;
    cin >> a >> b >> c >> x >> y >> z;

    if((verif(a, b, c) == 0) || (verif(x, y, z) == 0))
        cout << "nu";
    else
        if(a == x)
            if(b == y)
                if(c == z)
                    cout << "congruente";
                else
                    cout << "necongruente";
            else
                if(b == z)
                    if(c == y)
                        cout << "congruente";
                    else
                        cout << "necongruente";
                else
                    cout << "necongruente";
        else
            if(a == y)
                if(b == x)
                    if(c == z)
                        cout << "congruente";
                    else
                        cout << "necongruente";
                else
                    if(b == z)
                        if(c == x)
                            cout << "congruente";
                        else
                            cout << "necongruente";
                    else
                        cout << "necongruente";
            else
                if(a == z)
                    if(b == x)
                        if(c == y)
                            cout << "congruente";
                        else
                            cout << "necongruente";
                    else
                        if(b == y)
                            if(c == x)
                                cout << "congruente";
                            else
                                cout << "necongruente";
                        else
                            cout << "necongruente";
    return 0;
}
