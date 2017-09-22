#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[255],t[255]="",v[]="aeiou";
    cin.getline(s,255);
    int i,x;
    x=0;
    for(i=0;i<strlen(s);i++)
    {
        t[x]=s[i];
        x++;
        if(strchr(v,s[i])!=NULL){
            t[x]='p';
            t[x+1]=s[i];
            x+=2;
        }
    }
    cout<<t;
    return 0;
}
