#include <iostream>

using namespace std;

int Nr(int n)
{
    int tens = 1;
    int aux = n;

    while(aux)
    {
        tens *= 10;
        aux /= 10;
    }
    tens /= 10;
    return n % tens;
}

int main()
{
    int n;
    cin >> n;
    cout << Nr(n);
    return 0;
}
