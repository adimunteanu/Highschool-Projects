#include <iostream>

using namespace std;

int CMMDC(int a, int b)
{
    while(b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main()
{
    int a, b;
    cin >> a >> b;
    int cmmdc = CMMDC(a, b);
    for(int i = 1; i <= cmmdc ; i++)
        if(cmmdc % i == 0)
            cout << i << " ";
    return 0;
}
