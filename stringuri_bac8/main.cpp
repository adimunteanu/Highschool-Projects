#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char a[255],v[ ]="BCDFGHJKLMNPQRSTVWXYZ";
    int i=0,spc=1,vl=21,j;
    bool ok;
    cin.getline(a,255);
    for(i=0;i<strlen(a);i++)
        if(a[i]==' ') spc++;
    cout<<spc<<endl;
    for(i=0;i<vl;i++)
    {
        ok=true;
        j=0;
        while(ok&&j<strlen(a)){
            if(a[j]==v[i]){
                ok=false;
            }
            j++;
        }
        if(ok==false){
            cout<<v[i]<<" ";
        }
    }
    return 0;
}
