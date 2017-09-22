#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char a[50];
    int i,x=0,y=0,z=0;
    cin.getline(a,50);
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]==toupper(a[i])) x++;
        else if(a[i]==tolower(a[i])) y++;
            else z++;
    }
    cout<<x<<" "<<y<<" "<<z;
    return 0;
}
