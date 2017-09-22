#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char a[255];
    int i;
    cin.getline(a,255);
    i=strlen(a);
    while(i>=0){
        if(strchr("aeiou",a[i])==0){
            strcpy(a+i,a+i+1);
            break;
        }
       i--;
    }
    cout<<a;
    return 0;
}
