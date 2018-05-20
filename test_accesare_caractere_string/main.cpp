#include <iostream>
#include <string>

using namespace std;

int main()
{
    string x;
    cin >> x;
    for(int i = 0; i <= x.length(); i++)
        cout << x[i];
    return 0;
}
