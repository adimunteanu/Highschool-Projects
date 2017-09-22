#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char a[255],v[]="aeiou";
    cin.getline(a,255);
    for(int i=strlen(a)-1;i>=0;i--){
        if(strchr(v,a[i])!=NULL && a[i-1]=='p' &&a[i-2]==a[i]){
            strcpy(a+i,a+i+1);
            i--;
            strcpy(a+i,a+i+1);
        }
    }
    cout<<a;
    return 0;
}
