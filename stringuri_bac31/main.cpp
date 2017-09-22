#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char a[100],b[100]="",v[]="aeiouAEIOU";
    cin.getline(a,100);
    int i,x=-1;
    for(i=0;i<strlen(a);i++)
    {
        x++;
        b[x]=a[i];
        if(strchr(v,a[i])!=NULL){
            x++;
            b[x]='*';
        }
    }
    if(x==strlen(a)-1){
        cout<<"FARA VOCALE";
    }else{
        cout<<b;
    }
    return 0;
}
