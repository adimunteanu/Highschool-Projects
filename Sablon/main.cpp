#include <iostream>
#include <cstring>

using namespace std;

char a[32], b[32];

int main()
{
    cin >> a >> b;
    for(int i = 0; i < strlen(a); i++)
        if(strchr("aeiou", a[i]) == NULL && strchr("aeiou", b[i]) == NULL)
            cout << "#";
        else
            if(strchr("aeiou", a[i]) != NULL && strchr("aeiou", b[i]) != NULL)
                cout << "*";
            else
                cout << "?";
    return 0;
}
