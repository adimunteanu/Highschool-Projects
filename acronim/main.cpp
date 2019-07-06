#include <bits/stdc++.h>

using namespace std;

int main()
{
    char x[101], nou[100];
    cin.getline(x, 101);
    char *p = strtok(x, " ");
    int i = -1;
    while(p != NULL)
    {
        if(isupper(p[0])){
            i++;
            nou[i] = p[0];
            nou[i+1] = 0;
        }
        p = strtok(NULL, " ");
    }
    cout << nou;
    return 0;
}
