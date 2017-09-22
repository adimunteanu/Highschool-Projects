#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char a[20],x='b';
    cin.getline(a,20);
    int i;
    for(i=0;i<strlen(a);i++){
        x=a[i];
        if(strchr("aeiou",x)>0){
            cout<<x;
            x=toupper(x);
            cout<<x;
        }else cout<<x;
    }

    return 0;
}
