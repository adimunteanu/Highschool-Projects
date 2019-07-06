#include <iostream>

using namespace std;

int rec[1000];
int output[2], len = 0;

int main()
{
    int n, i = 2, j = 999;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        if(x < 1000)
            rec[x] = 1;
    }

    while(i && j)
    {
        if(!rec[j]){
            output[len++] = j;
            i--;
        }
        j--;
    }
    if(i)
        cout << "NU EXISTA";
    else {
        cout << output[1] << " " << output[0];
    }
    return 0;
}
