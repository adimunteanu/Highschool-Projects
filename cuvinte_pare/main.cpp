#include <iostream>
#include <cstring>

using namespace std;

char a[256];

int main()
{
    cin.getline(a, 256);
    int lCuv = 0;
    bool exista = false;
    for(int i = 0; i <= strlen(a); i++)
    {
        if(a[i] != ' ' && i!= strlen(a))
            lCuv++;
        else {
            if(lCuv % 2 == 0 && lCuv != 0){
                exista = true;
                char t[256];
                strcpy(t, a + i);
                strcpy(a + i - lCuv, t);
                i -= lCuv;
                strcpy(t, a + i);
                strcpy(a + i + 1, t);
                a[i] = '#';
            }
            lCuv = 0;
        }
    }
    if(exista)
        cout << a;
    else
        cout << "nu exista";
    return 0;
}
