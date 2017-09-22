#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char a[100],v[ ]="aeiou";
    int i;
    cin.getline(a,100);
    for(i=0;i<strlen(a);i++){
        if(a[i]=='a') a[i]='b';
        else if(a[i]=='e') a[i]='f';
            else if(a[i]=='i') a[i]='j';
                else if(a[i]=='o') a[i]='p';
                    else if(a[i]=='u') a[i]='v';
    }
    cout<<a;
    return 0;
}
