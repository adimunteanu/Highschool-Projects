#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char a[255],x;
    int i;
    cin.getline(a,255);
    x=toupper(a[0]);
    cout<<x;
    for(i=1;i<strlen(a);i++){
        if((a[i-1]==' ')&&(a[i]!=' ')){
            x=toupper(a[i]);
            cout<<x;
        }else
        cout<<a[i];
    }
    return 0;
}
