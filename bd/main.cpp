#include <iostream>

using namespace std;

int k = 0;

int elimcif(int n, int c)
    {
        if(n < 10)
            {
                if(n != c)
                k = n;
            }
        else
            {
                elimcif(n/10,c);
                if(n % 10 != c)
                    k = k * 10 + n % 10;
            }
        return k;
    }
