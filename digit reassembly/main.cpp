#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");

int a[1000000], s[1000000];
int sIndex = 1;
char in[1000000];
int maxLen = 0;
long long n;

void checkIfLongest(int x){
    if(x > maxLen)
        maxLen = x;
}

void add(int sf)
{
    for(int j = sf; j > sf - n; j--)
        if(a[j] + s[sIndex] < 10){
            s[sIndex] += a[j];
            sIndex++;
        } else {
            s[sIndex] += a[j] - 10;
            sIndex++;
            s[sIndex]++;
        }
    checkIfLongest(sIndex--);
}

int main()
{
    for(int index = 1; index <= 5; index++)
    {
        fin >> in >> n;
        int len = strlen(in);

        for(long long i = 0; i < len; i++)
            a[i+1] = in[i] - 48;

        for(int i = len; i >= n; i--){
            add(i);
            sIndex = 1;
        }

        for(int i = maxLen; i >= 1; i--)
            cout << s[i];
        cout << endl;

        for(int i = 1; i <= maxLen; i++)
            s[i] = 0;
        maxLen = 0;
    }
    return 0;
}
