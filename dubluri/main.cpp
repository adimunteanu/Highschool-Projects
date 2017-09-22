#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char a[255],b[122]="",aux[255],s[123]="z",clearstr[255]="";
    cin.getline(a,255);
    int i,j,k;
    for(k=1;k<strlen(a)/2;k++)
        for(i=k;i<strlen(a)/2;i++){
            for(j=0;j<=i;j++){
                b[j]=a[j];
            }
            strcpy(aux,a);
            for(j=i;j>=0;j--){
                strcpy(aux+j,aux+j+1);
            }
            if(strstr(aux,b)!=0){
                if(strcmp(s,b)>0){
                    strcpy(s,b);
                }
            }
            for(j=i;j>=0;j--){
                strcpy(b+j,b+j+1);
            }
        }
    return 0;
}
