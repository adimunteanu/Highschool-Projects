#include <iostream>
#include <cstring>

using namespace std;

char a[101], t[101];
int n;
bool areVocale = false;

int main()
{
    cin.getline(a, 101);
    for(int i = 0; i < strlen(a); i++)
        if(strchr("aeiou", a[i]) != NULL){
            areVocale = true;
            strcpy(t, a + i);
            strcpy(a + i + 1, t);
            a[i + 1] = '*';
        }
    if(areVocale)
        cout << a;
    else cout << "FARA VOCALE";
    return 0;
}
