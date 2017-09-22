#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char a[20],v[]="aeiouAEIOU";
    int i,j;
    bool ok1,ok2;
    cin.getline(a,20);
    i=0;
    j=strlen(a)-1;
    ok1=true;
    ok2=true;
    while(i<strlen(a) && ok1){
        if(strchr(v,a[i])==NULL){
            ok1=false;
            i--;
        }
        i++;
    }
    while(j>=0 && ok2){
        if(strchr(v,a[j])!=NULL){
            ok2=false;
            j++;
        }
        j--;
    }
    if(ok1 || ok2){
        cout<<"IMPOSIBIL";
    }else {
        swap(a[i],a[j]);
        cout<<a;
    }
    return 0;
}
