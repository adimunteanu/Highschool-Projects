#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    char out[255];
    out[0] = 0;
    cin >> n;
    char cuv[n][21];
    for(int i = 0; i < n; i++)
        cin >> cuv[i];
    cin >> k;

    for(int i = 0; i < n; ++i)
        if(strlen(cuv[i]) == k){
            strcat(out, cuv[i]);
            strcat(out, " ");
        }
    for(int i = 0; i < n; ++i)
        if(strlen(cuv[i]) != k){
            strcat(out, cuv[i]);
            strcat(out, " ");
        }
    cout << out;
    return 0;
}
