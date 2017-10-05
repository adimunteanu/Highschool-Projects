#include <iostream>

using namespace std;

int sum_cifra_control(int a, int b)
{
    int nr = 1;
    for(int i = 10; i <= b; i++)
    {
        bool ok = true;
        int aux = i;
        int sum = 0;
        while(ok)
        {
            while(aux)
            {
                sum += aux % 10;
                aux /= 10;
            }
            if(sum > 9){
                aux = sum;
                sum = 0;
            } else {
                if(sum == a){
                    ok = false;
                    nr++;
                }
                ok = false;
            }
        }
    }

    return nr;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << sum_cifra_control(a, b);
    return 0;
}
