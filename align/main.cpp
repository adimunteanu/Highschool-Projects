#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    char a[101][208],x,aux[208];
    int n,i,j;
    ifstream fin("align.in");
    ofstream fout("align.out");
    fin>>n;
    fin>>x;
    fin.get();
    int mx=0;
    for(i=1;i<=n;i++){
        fin.getline(a[i],208);
        if(strlen(a[i])>mx) mx=strlen(a[i]);
    }
    if(x=='D'){
        for(i=1;i<=n;i++){
            if(mx!=strlen(a[i])){
                aux[0]=0;
                for(j=0;j<mx-strlen(a[i]);j++){
                    strcat(aux," ");
                }
                strcat(aux,a[i]);
                strcpy(a[i],aux);

            }
        }
        for(j=1;j<=n;j++){
                fout<<a[j]<<'\n';
                cout<<a[i]<<'\n';
            }
    }
    else
    {
        if(x=='S'){
            for(i=1;i<=n;i++)
            {
                int p=0;
                while(a[i][p]==' ' and strlen(a[i])>0)
                        ++p;
                strcpy(aux,a[i]+p);
                a[i][0]=0;
                strcpy(a[i],aux);
            }
            for(j=1;j<=n;j++){
             fout<<a[j]<<'\n';
            }
        }


    }
    return 0;
}
