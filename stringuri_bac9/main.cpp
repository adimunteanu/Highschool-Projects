#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char a[255];
    int i;
    cin.getline(a,255);
    a[0]=toupper(a[0]);
    for(i=1;i<strlen(a)-1;i++){
        if(a[i]!=' '&&a[i+1]==' '){
            a[i]=toupper(a[i]);
        }
        if(a[i]!=' '&&a[i-1]==' '){
            a[i]=toupper(a[i]);
        }
    }
    a[strlen(a)-1]=toupper(a[strlen(a)-1]);
    cout<<a;
    return 0;
}
