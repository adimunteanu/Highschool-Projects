#include <iostream>
#include <cstring>


using namespace std;

int main()
{
    char a[250],b[250],c[250]="",aux;
    int i,j;
    cin.getline(a,250);
    cin.getline(b,250);
    strcat(c,a);
    strcat(c,b);
    for(i=0;i<strlen(c)-1;i++)
        for(j=i+1;j<strlen(c);j++){
            if(c[i]>c[j]){
                aux=c[i];
                c[i]=c[j];
                c[j]=aux;
            }
        }
    cout<<c;
    return 0;
}
