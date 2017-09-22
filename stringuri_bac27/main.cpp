#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char a[255],*p,v[]="aeiou";
    int i,cuv=0,vcuv=0;
    cin.getline(a,50);
    p=strtok(a," ");
    cuv++;
    if(strchr(v,p[0])!=NULL){
        vcuv++;
    }
    p=strtok(NULL," ");
    while(p){
        cuv++;
        if(strchr(v,p[0])!=NULL){
            vcuv++;
        }
        p=strtok(NULL," ");
    }
    cout<<cuv<<" "<<vcuv;
    return 0;
}
