#include <iostream>

using namespace std;

int fibo[10000], output[10000];

int main()
{
    int n, a = 1, b = 1, c, l = 0;
    cin >> n;
    if(n == 1)
    {
        cout << 1;
    } else {
        fibo[1] = 1;
        fibo[2] = 1;
        int i = 3;
        while(fibo[i - 2] + fibo[i - 1] <= n){
            fibo[i] = fibo[i - 2] + fibo[i - 1];
            i++;
        }
        int sum = 0;
        i--;
        while(sum != n)
        {
            if(sum + fibo[i]> n){
                i--;
            } else {
                output[++l] = fibo[i];
                sum += fibo[i];
            }
        }
        for(int j = 1; j <= l; j++)
        {
            cout << output[j] << " ";
        }
    }
    return 0;
}
