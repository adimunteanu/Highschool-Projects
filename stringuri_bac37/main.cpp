#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char a[20],b[20],v[]="aeiou",c[40];
    cin.getline(a,20);
    cin.getline(b,20);
    int i;
    for(i=0;i<strlen(b);i++)
        if(strchr(v,b[i])>0)
        {
           strcpy(b+i,b+i+1);
           i--;
        }
    strcpy(c,b);
    strcat(c," ");
    strcat(c,a);
    cout<<c;
    return 0;
}

