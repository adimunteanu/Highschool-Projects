#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char a[250],b[250],x;
    int i=0,j=0;
    bool ok=true;
    cin.getline(a,250);
    cin.get();
    cin.getline(b,250);
    for(i=0;i<strlen(a);i++){
        ok=true;
        j=0;
        while(j<strlen(b) && ok)
        {
            if(a[i]==b[j]){
                cout<<a[i];
                x=a[i];
                ok=false;
            }
            j++;
        }
        if(ok==false){
            for(j=0;j<strlen(a);j++){
                if(x==a[j]) {
                        strcpy(a+j,a+j+1);
                        j--;
                }
            }
            i--;
        }
    }
    return 0;
}
