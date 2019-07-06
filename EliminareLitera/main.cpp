#include <iostream>
#include <cstring>

using namespace std;

char a[101], b[101];
char sep[] = " ";
char t[50];
bool exista = false;

int main()
{
    cin.getline(a, 101);
    char *p = strtok(a, sep);
    while(p != NULL)
    {
        if(strlen(p) % 2 == 1 && strlen(p) >= 3){
            exista = true;
            strcpy(t, p + strlen(p) / 2 + 1);
            strcpy(p + strlen(p) / 2 , t);
        }
        char aux[101];
        strcpy(aux, p);
        strcpy(t, aux + strlen(aux) - 1);
        strcpy(aux + strlen(aux) , t);
        aux[strlen(aux) - 1] = ' ';
        strcat(b, aux);
        p = strtok(NULL, sep);
    }
    if(exista){
        cout << b;
    } else {
        cout << "nu exista";
    }
    return 0;
}
