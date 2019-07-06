#include <iostream>
#include <cstring>

using namespace std;

char a[256];

int main()
{
    cin.getline(a, 256);
    int lCuv = 0;
    for(int i = 0; i <= strlen(a); i++)
    {
        if(a[i] != ' ' && i!= strlen(a))
            lCuv++;
        else {
            if(lCuv == 3){
                char t[256];
                strcpy(t, a + i);
                strcpy(a + i - 3, t);
                i -= 3;
                strcpy(t, a + i);
                strcpy(a + i + 1, t);
                a[i] = '*';
            }
            lCuv = 0;
        }
    }
    cout << a;
    return 0;
}
