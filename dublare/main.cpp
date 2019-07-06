#include <iostream>
#include <cstring>

using namespace std;

char a[257];
int n, dublari = 0;
bool notMatching = false;

int main()
{
    cin.getline(a, 257);
    n = strlen(a);
    if(n % 2 == 1)
        cout << 0;
    else {
        while(n % 2 != 1 && !notMatching)
        {
            int i = 0, j = n - 1;
            while(i <= n / 2 - 1 && j >= n / 2)
            {
                if(a[i] != a[j]){
                    notMatching = true;
                    break;
                }
                i++; j--;
            }
            if(!notMatching){
                dublari++;
                n /= 2;
            }
        }
        cout << dublari;
    }
    return 0;
}
