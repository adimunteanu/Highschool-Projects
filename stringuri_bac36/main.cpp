#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char a[20],*p,*q,b[20]=" ";
    cin.getline(a,20);
    p=strtok(a," ");
    q=strtok(NULL," ");
    b[0]=q[0];
    strcat(b,". ");
    strcat(b,p);
    cout<<b;
    return 0;
}
