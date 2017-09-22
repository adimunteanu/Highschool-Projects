#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char a[200],b[200],s[200],v[]="aeiou";
    cin.getline(a,200);
    cin.getline(b,200);
    int k=0;
    for(int i=0;i<strlen(a);i++)
    {
        if(strchr(v,a[i])!=NULL)
        {
            if(strchr(v,b[i])!=NULL)
            {
                s[k]='*';
                k++;
            }
            else{
                s[k]='?';
                k++;
            }
        }
        else
        {
            if(strchr(v,a[i])==NULL)
            {
                if(strchr(v,b[i])==NULL)
                {
                    s[k]='#';
                    k++;
                }
                else{
                    s[k]='?';
                k++;
                }
            }
        }
    }
    for(int j=0;j<k;j++){
        cout<<s[j];
    }
    return 0;
}
