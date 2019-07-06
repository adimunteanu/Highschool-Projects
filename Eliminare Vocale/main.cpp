#include <iostream>
#include <cstring>

using namespace std;

char a[256], b[256];
int perechi = 0;

int main()
{
    cin.getline(a, 256);
    for(int i = 0; i < strlen(a) - 1; i++)
        if(strchr("aeiou", a[i]) != NULL)
            if(strchr("aeiou", a[i + 1]) != NULL)
                perechi++;

    cout << perechi;
    return 0;
}
