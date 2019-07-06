#include <bits/stdc++.h>

using namespace std;

int main()
{
    char a[257], nou[257];
    cin.getline(a, 256);
    char *p = strtok(a, " ");

    nou[0] = 0;
    while(p != NULL)
    {
        strcat(nou, p);
        strcat(nou, " ");
        p = strtok(NULL, " ");
    }
    cout << nou;
    return 0;
}
