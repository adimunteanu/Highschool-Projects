#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char a[255];
    int i,j;
    cin.getline(a,255);
    i=0;
    j=strlen(a)-1;
    while(strlen(a)!=0)
    {
        cout<<a<<endl;
        strcpy(a,a+1);
        strcpy(a+strlen(a)-1,a+strlen(a));
    }

    return 0;
}
