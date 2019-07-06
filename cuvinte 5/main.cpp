#include <iostream>
#include <cstring>

using namespace std;

char a[257], vocale[] = "AEIOUaeiou", memo[31][12];
char *cuv;
int nrCuv3Lit = 0, nmem, maxx;

int main()
{
    cin.getline(a, 257);
    cuv = strtok(a, " ");
    while(cuv != 0)
    {
        //treaba
        char aux[257];
        strcpy(aux, cuv);
        if(strlen(aux) == 3)
            nrCuv3Lit++;
        if(strchr(vocale, aux[0]) != NULL && strchr(vocale, aux[strlen(aux)-1]) != NULL)
        {
            nmem++;
            strcpy(memo[nmem], aux);
        }
        if(strlen(aux) > maxx)
            maxx = strlen(aux);
        cuv = strtok(NULL, " ");
    }
    cout << nrCuv3Lit << endl;
    for(int i = 1; i <= nmem; i++)
        cout << memo[i] << endl;
    cout << maxx;
    return 0;
}
