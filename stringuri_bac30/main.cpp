#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char a[100],b[15],*p,c[200]="";
    bool ok=false;
    cin.getline(a,100);
    cin.getline(b,15);
    p=strtok(a," ");
    while(p){
        strcat(c,p);
        if(strcmp(p,b)==0){
            strcat(c,"?");
            ok=true;
        }
        strcat(c," ");
        p=strtok(NULL," ");
    }
    if(ok){
        cout<<c;
    }
    else {
        cout<<"NU APARE";
    }
    return 0;
}
