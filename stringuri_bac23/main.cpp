#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char a[255],v[]="abcdefghijklmnopqrstuvwxyz";
    int i,j;
    cin.getline(a,255);
    for(i=0;i<strlen(a);i++){
        if(strchr(v,a[i])!=NULL){
            for(j=0;j<strlen(v)-1;j++)
            {
                if(a[i]==v[j]){
                    strcpy(v+j,v+j+1);
                }
            }
            cout<<a[i]<<" ";
        }
    }
    return 0;
}
