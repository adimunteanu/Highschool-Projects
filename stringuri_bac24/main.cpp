#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char a[200],*p,v[]="AEIOUaeiou";
    cin.getline(a,200);
    int c=0;
    p=strtok(a," ");
    if(strchr(v,p[0])!=NULL && strchr(v,p[strlen(p)-1])!=NULL){
        c++;
    }
    p=strtok(NULL," ");
    while(p)
    {
        if(strchr(v,p[0])!=NULL && strchr(v,p[strlen(p)-1])!=NULL){
            c++;
        }
        p=strtok(NULL," ");
    }
    cout<<c;
    return 0;
}
