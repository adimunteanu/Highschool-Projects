#include <iostream>

using namespace std;

int n, pare, impare;
long long permutari;

int main()
{
    cin >> n;

    if(n % 2 == 1){
        cout << 0;
    } else {
        impare = n / 2;
        pare = n / 2;
        permutari = 1;
        for(int i = 1; i <= impare; i++)
            permutari *= i;
        for(int i = 1; i <= pare; i++)
            permutari *= i;
        cout << permutari;
    }
    return 0;
}
