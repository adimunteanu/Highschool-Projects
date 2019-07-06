#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s[102];
    int start = 0;
    cin.getline(s, 101);

    for(int i = 0 ; i < strlen(s); ++i)
    {
        if(isNum){
            if(s[i] == '.')
                isFrac = true;
            if(s[i] == ' ' && isFrac)
            {
                //remove seq
            } else {
                isNum = false;
            }
        }
    }
    return 0;
}
