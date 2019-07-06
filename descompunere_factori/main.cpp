#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n == 2){
        cout << 2;
    } else if (n == 3)
        cout << 3;
        else {
            int f = 2;
            while(n != 1 && f <= n / 2)
            {
                while(n % f == 0)
                {
                    n /= f;
                    cout << f << " ";
                }
                if(f == 2) f++;
                    else f += 2;
            }
        }

    return 0;
}
