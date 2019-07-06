#include <iostream>
#include <cstring>

using namespace std;

char a[256];
int frecventa[26];

int main()
{
    cin.getline(a, 256);
    for(int i = 0; i < strlen(a); i++)
        if(a[i] >= 'a' && a[i] <= 'z')
            frecventa[a[i] - 97]++;
    int maxx = 0, pozitie;
    for(int i = 0; i < 26; i++)
        if(frecventa[i] > maxx){
            maxx = frecventa[i];
            pozitie = i;
        }
    cout << char(pozitie + 97);
    return 0;
}
