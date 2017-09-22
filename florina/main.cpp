#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

int sol[10];
char S[20];

ifstream f("anagrame1.in");
ofstream g("anagrame1.out");

int ok(int k)
{
    for(int i = 0; i < k; i++)
        if(S[sol[k]] == S[sol[i]])
            return 0;
    return 1;
}

void back(int k)
{
    if (k == strlen(S))
    {
        for(int i = 0; i < strlen(S); i++)
            g << S[sol[i]];
        g << endl;
    } else
        for(int i = 0; i < strlen(S); i++)
        {
            sol[k] = i;
            if(ok(k) == 1)
                back(k+1);
        }
}

int main ()
{
    f >> S;

    for(int i = 0; i < strlen(S)-1; i++)
        for(int j = i + 1; j < strlen(S); j++)
            if(S[i] > S[j])
                swap(S[i], S[j]);
    back(0);

    return 0;
}
