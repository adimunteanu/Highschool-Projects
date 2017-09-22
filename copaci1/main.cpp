#include <fstream>
#include <iostream>

using namespace std;

int a[102][102];
int dl[5]={0,-1,0,1,0};
int dc[5]={0,0,1,0,-1};


int main()
{
    ifstream fin("copaci1.in");
    ofstream fout("copaci1.out");
    int i,j,trees,days=0,n,m,k;
    bool hasPlanted=true,imposible=false;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            fin>>a[i][j];
    while(hasPlanted){
        days++;
        hasPlanted=false;
        imposible=false;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++){
                if(a[i][j]==0){
                    imposible=true;
                    trees=0;
                    for(k=1;k<=4;k++){
                        if(a[i+dl[k]][j+dc[k]]==1){
                            trees++;
                        }
                    }
                    if(trees>=2){
                        a[i][j]=2;
                        hasPlanted=true;
                    }
                }
            }
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++)
                if(a[i][j]==2){
                    a[i][j]=1;
                    cout<<a[i][j]<<" ";
                } else cout<<a[i][j]<<" ";
            cout<<endl;
        }
    }
    if(imposible){
        fout<<"IMPOSIBIL";
    } else {
        days--;
        fout<<days;
    }
    return 0;
}



