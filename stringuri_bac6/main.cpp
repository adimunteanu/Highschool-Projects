#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char a[20],b[20],v[]="aeiou",c;
    int i,j,vl=5;
    cin.getline(a,20);
    strcpy(b,a);
    for(i=0;i<strlen(a);i++)
    {
        if(strchr(v,a[i])>0){
            c=a[i];
            for(j=i;j<strlen(a);j++){
                if(c==b[j]){
                    strcpy(b+j,b+j+1);
                    j--;
                }
            }
            for(j=0;j<vl;j++){
                if(v[j]==c){
                    strcpy(v+j,v+j+1);
                }
            }
            vl--;
            cout<<b<<endl;
            strcpy(b,a);
        }
    }
    return 0;
}
