#include <iostream>
#include <cstring>

using namespace std;

char a[257];
char *cuv;
int d = 0;

int main()
{
    cin.getline(a, 257);
    cin >> d;
    cuv = strtok(a, " ");
    while(cuv != 0)
    {
        //treaba
        char aux[257];
        strcpy(aux, cuv);
        for(int j = 0; j < strlen(aux); j++)
            if(aux[j] + d > 'z')
                aux[j] = char(int(aux[j]) + d - 26);
            else
                aux[j] = char(int(aux[j]) + d);
        cout << aux << " ";
        cuv = strtok(NULL, " ");
    }
    return 0;
}
