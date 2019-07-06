#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s[71];
    cin.getline(s, 71);
    char *p = strtok(s, " ");
    int nrA = 0;

    while(p != NULL)
    {
        if(strstr(p, "a") != NULL)
            nrA++;
        p = strtok(NULL, " ");
    }
    cout << nrA;
    return 0;
}
