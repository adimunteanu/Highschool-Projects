#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char a[50],b[50]="";
    int i;
    cin.getline(a,50);
    for(i=1;i<strlen(a);i++)
    {
        strncpy(b,a,i);
        cout<<b<<endl;
    }
    cout<<a;
    return 0;
}
