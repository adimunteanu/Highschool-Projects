#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char a[100];
    int i=0,x=0;
    cin.getline(a,100);
    for(i=0;i<strlen(a);i++)
    {
        if('a'<=a[i] && a[i]<='z'){
            a[i]=toupper(a[i]);
        }
        else
        {
            if('A'<=a[i] && a[i]<='Z'){
                a[i]=tolower(a[i]);
            }
            else x++;
        }
    }
    cout<<a<<endl;
    cout<<x;
    return 0;
}
