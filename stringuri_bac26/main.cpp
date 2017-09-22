#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char a[50];
    int i;
    cin.getline(a,50);
    for(i=strlen(a)-1;i>=0;i--)
        cout<<a+i<<endl;
    return 0;
}
