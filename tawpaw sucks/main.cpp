#include <iostream>

using namespace std;


int main()
{
    int notFound = 1, prim1 = 2, prim2 = 3, n, isntPrime = 1, notPrime = 0;
    cin >> n;
    if(n % 2 == 0)
        cout << "subscribe to pewdiepie";
    else {
        while(notFound){
            if(prim2 - prim1 - 1 == n){
                for(int i = prim1 + 1; i < prim2; i++)
                    cout << i << " ";
                notFound = 0;
                break;
            }
            else {
                prim1 = prim2;
                while(isntPrime){
                    prim2++;
                    for(int i = 2; i < prim2; i++)
                        if(prim2 % i == 0)
                            notPrime = 1;
                    if(!notPrime)
                        isntPrime = 0;
                    notPrime = 0;
                }
                isntPrime = 1;
            }
        }
    }
}
