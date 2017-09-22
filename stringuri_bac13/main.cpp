#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char a[40],b[40];
    int i;
    cin.getline(a,40);
    strcpy(b,a);
    for(i=0;i<strlen(a);i++){
        strcpy(b+i,b+i+1);
        cout<<b<<endl;
        strcpy(b,a);
    }
    return 0;
}
