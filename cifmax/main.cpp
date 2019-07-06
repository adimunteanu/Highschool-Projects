#include <iostream>
#include <cstring>

using namespace std;

char a[256];
int frecventa[26];

int main()
{
    cin.getline(a, 256);
    for(int i = 0; i < strlen(a); i++)
        if(a[i] >= '0' && a[i] <= '9')
            frecventa[a[i] - 48]++;
    int maxx = 0, pozitie;
    for(int i = 0; i < 26; i++)
        if(frecventa[i] > maxx){
            maxx = frecventa[i];
            pozitie = i;
        }
    if(maxx == 0)
        cout << "NU";
    else
        cout << char(pozitie + 48);
    return 0;
}
