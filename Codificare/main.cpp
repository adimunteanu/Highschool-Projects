#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s[102], c[102], nou[103];
    cin >> s >> c;
    if(strlen(s) == strlen(c)){
        nou[0] = s[0];
        nou[1] = 0;
        for(int i = 1; i < strlen(s); ++i)
        {
            if(int(c[i]) % 2 == 0){
                char aux[102];
                strcpy(aux, nou);
                strcpy(nou + 1, aux);
                nou[0] = s[i];
            } else {
                char aux[102];
                strcpy(aux, nou + strlen(nou) - 1);
                strcpy(nou + strlen(nou), aux);
                nou[strlen(nou) - 1] = s[i];
            }
        }
        cout << nou;
    } else
        cout << "cod incorect";
    return 0;
}
