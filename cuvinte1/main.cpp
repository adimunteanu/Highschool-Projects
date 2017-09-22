#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char a[255],*p,v[]="aeiou";
    bool ok;
    int i;
    cin.getline(a,255);
    p=strtok(a," ");
    while(p){
        ok=false;
        for(i=0;i<strlen(p);i++){
            if(strchr(v,p[i])==NULL){
                ok=true;
            }
        }
        if(ok==false){
            cout<<p<<endl;
        }
        p=strtok(NULL," ");
    }
    return 0;
}
