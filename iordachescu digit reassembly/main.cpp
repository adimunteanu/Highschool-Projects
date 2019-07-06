#include <bits/stdc++.h>

using namespace std;

const int CMAX = 51 + 10;
ifstream fin("input.txt");
ofstream fout("digit.out");

long long add(char x[], int poz, int n)
{
    long long num = 0;
    for (int i = poz; i <= poz + n - 1; ++i)
    {
        num *= 10;
        num += (long long)(x[i] - '0');
    }
    return num;
}

void sum(char x[], int n)
{
    long long s = 0;
    for (int i = 0; i < strlen(x) - n + 1; ++i)
        s += add(x, i, n);
    cout << s << '\n';
}
int main()
{
    for (int test = 1; test <= 5; ++test)
    {
        char x[CMAX];
        fin.getline(x, 56);
        char *p = strtok(x, " ");
        char *q = p;
        p = strtok(NULL, " ");
        int b = add(p, 0, strlen(p));
        sum(q, b);
    }
    return 0;
}
