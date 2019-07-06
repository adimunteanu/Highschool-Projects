#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char a[21], b[21];

int main()
{
    cin >> a >> b;
    sort(a, a + strlen(a));
    sort(b, b + strlen(b));
    if(strcmp(a, b) == 0)
        cout << 1;
    else cout << 0;
    return 0;
}
