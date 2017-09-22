#include <iostream>

using namespace std;

int sub(int n)
{
    if(n <= 5) {
        return n;
    } else {
        int number = 5;

        while(number * 2 < n)
            if(number * 2 >= n)
                return number;
            else
                number *= 2;

        return number;
    }
}

int main()
{
    int s;
    cin >> s;

    while(s){
        cout << sub(s) << " ";
        s -= sub(s);
    }

    return 0;
}
