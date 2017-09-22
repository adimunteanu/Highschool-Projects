#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char a[255],*p,x[10]="z";
    int i,j;
    bool ok=true,pal=false;
    cin.getline(a,255);
    p=strtok(a," ,.");
    while(p){
        i=0;
        j=strlen(p)-1;
        ok=true;
        while(i!=j && ok){
            if(p[i]!=p[j])
            {
                ok=false;
            }
            i++;
            j--;
        }
        if(ok && p[0]<x[0]){
            strcpy(x,p);
            pal=true;
        }
        p=strtok(NULL," ,.");
    }
    if(pal&&strlen(x)>1){
        cout<<x;
    }
    else{
        cout<<"IMPOSIBIL";
    }
    return 0;
}
