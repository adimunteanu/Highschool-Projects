#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char a[40],v[ ]="aeiou";
    int i;
    cin.getline(a,40);
    for(i=0;i<strlen(a);i++)
        if(strchr(v,a[i])>0) cout<<a[i]<<" ";
    return 0;
}
