#include <iostream>

using namespace std;

int f(int x, int y)
{
    if(x == y)
        return x * x + y;
    else
        if(x > y)
            return f(x - 1, y + 2) + 3;
        else
            return 2 * f(x + 1, y - 1) - 5;
}

int main()
{
    cout << f(12, 7);
}
