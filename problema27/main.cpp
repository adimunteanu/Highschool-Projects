#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char a[100];
    int i,j;
    cin.getline(a,100);
    bool ok=true;
    while(ok){
        ok=false;
        for(i=0;i<strlen(a);i++)
        {
            if(a[i]==a[i+1])
            {
                ok=true;
                strcpy(a+i,a+i+1);
                i--;
                j=i+1;
                while(a[j]==a[j+1])
                {
                    strcpy(a+j,a+j+1);
                }
                strcpy(a+j,a+j+1);
            }
        }
    }
    cout<<a;
    return 0;
}
