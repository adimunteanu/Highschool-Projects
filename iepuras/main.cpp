#include <iostream>
#include <fstream>
using namespace std;

int a[202][202],zid[3][21];
int dl[5]={0,-1,0,1,0};
int dc[5]={0,0,-1,0,1};

int main()
{
    int m,n,t,i,j,colI,linI,dirI,morcoviI=0,morcovi=0;
    bool isFericit=false,isRatacit=false,isIngeras=false;
    ifstream fin("iepuras.in");
    ofstream fout("iepuras.out");
    fin>>m>>n;
    fin>>linI>>colI>>dirI;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            fin>>a[i][j];
            if(a[i][j]==7) morcovi++;
        }
    fin>>t;
    if(t!=0){
        for(i=1;i<=t;i++)
        {
            fin>>zid[1][i];
            fin>>zid[2][i];
        }
    }
    while(isFericit==false || isRatacit==false || isIngeras==false)
    {
        for(i=1;i<=4;i++)
            if(a[linI+dl[i]][colI+dc[i]]==6 || a[linI+dl[i]][colI+dc[i]]==16)
                a[linI+dl[i]][colI+dc[i]]=a[linI+dl[i]][colI+dc[i]]+10;
        for(i=1;i<=4;i++)
            if(a[linI+dl[i]][colI+dc[i]]==26)
            {
                isIngeras=true;
                break;
            }
        if(a[linI+dl[dirI]][colI+dc[dirI]]!=5 || a[linI+dl[dirI]][colI+dc[dirI]]!=8){
            linI=linI+dl[dirI];
            colI=colI+dc[dirI];
        } else {
            switch(dirI){
                case 1:
                    dirI=3;
                case 2:
                    dirI=4;
                case 3:
                    dirI=1;
                case 4:
                    dirI=2;
            }
            linI=linI+dl[dirI];
            colI=colI+dc[dirI];
        }
        switch(a[linI][colI]){
            case 1:
                dirI=1;
                break;
            case 2:
                dirI=2;
                break;
            case 3:
                dirI=3;
                break;
            case 4:
                dirI=4;
                break;
            case 6:
                isIngeras=true;
                break;
            case 16:
                isIngeras=true;
                break;
            case 7:
                morcoviI++;
                a[linI][colI]=0;
        }
        if(linI<1 || linI>m || colI<1 || colI>n) isRatacit=true;
    }
    return 0;
}
