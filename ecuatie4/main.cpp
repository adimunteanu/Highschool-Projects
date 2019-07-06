#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, x = 1;
    cin >> a >> b;
    int y = a * b;
    while(x <= 10000 && x < y){
        y = (b * x) / (a * x - b);
        if(int(y) == y && y > 0)
            cout << x << " " << y << endl;
        else y = 10000;
        x++;
    }
    return 0;
}
