#include <iostream>
#include <cstring>

using namespace std;

char nume[60], prenume[60], t[60];

int main()
{
    cin >> nume >> prenume;
    for(int i = 0; i < strlen(prenume); i++)
        if(strchr("aeiouAEIOU", prenume[i]) != NULL){
            strcpy(t, prenume + i + 1);
            strcpy(prenume + i, t);
            i--;
        }
    int n = strlen(prenume);
    strcat(prenume, nume);
    strcpy(t, prenume + n - 1);
    strcpy(prenume + n, t);
    prenume[n] = ' ';
    cout << prenume;
    return 0;
}
