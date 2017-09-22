#include <iostream>
#include <fstream>
using namespace std;

int a[100][100];

int dl_pion[5]={0,-1,0,1,0};
int dc_pion[5]={0,0,1,0,-1};

int dl_regina[9]={0,-1,-1,-1,0,1,1,1,0};
int dc_regina[9]={0,-1,0,1,1,1,0,-1,-1};

int dl_nebun[5]={0,-1,-1,1,1};
int dc_nebun[5]={0,-1,1,1,-1};

int dl_cal[9]={0,-2,-2,-1,1,2,2,1,-1};
int dc_cal[9]={0,-1,1,2,2,1,-1,-2,-2};

int main()
{
    ifstream fin("piesesah.in");
    ofstream fout("piesesah.out");
    char c;
    int n,m,t,i,j,x,piese[3][10000],piesa,k,y,z;
    fin>>n>>m>>t;
    for(i=1;i<=n;i++){
        a[0][i]=-7;
        a[n+1][i]=-7;
    }
    for(i=1;i<=n;i++){
        a[i][0]=-7;
        a[i][n+1]=-7;
    }
    for(x=1;x<=m;x++)
    {
        fin>>c;
        fin>>i>>j;
        piese[1][x]=i;
        piese[2][x]=j;
        switch(c){
            case 'p':
                a[i][j]=-1;
                break;
            case 'r':
                a[i][j]=-2;
                break;
            case 'q':
                a[i][j]=-3;
                break;
            case 'n':
                a[i][j]=-4;
                break;
            case 't':
                a[i][j]=-5;
                break;
            case 'c':
                a[i][j]=-6;
                break;
        }
    }
    for(x=1;x<=m;x++)
    {
        i=piese[1][x];
        j=piese[2][x];
        piesa=a[piese[1][x]][piese[2][x]];
        switch(piesa){
            case -1:
                for(k=1;k<=4;k++)
                {
                    if( a[i+dl_pion[k]][j+dc_pion[k]]>=0 &&
                        i+dl_pion[k]>0 && i+dl_pion[k]<=n &&
                        j+dc_pion[k]>0 && j+dc_pion[k]<=n
                    ){
                        a[i+dl_pion[k]][j+dc_pion[k]]=1;
                    }
                }
                break;
            case -2:
                for(k=1;k<=8;k++)
                {
                    if( a[i+dl_regina[k]][j+dc_regina[k]]>=0 &&
                        i+dl_regina[k]>0 && i+dl_regina[k]<=n &&
                        j+dc_regina[k]>0 && j+dc_regina[k]<=n
                    ){
                        a[i+dl_regina[k]][j+dc_regina[k]]=1;
                    }
                }
                break;
            case -3:
                for(k=1;k<=8;k++)
                {
                    y=dl_regina[k];
                    z=dc_regina[k];
                    while(a[i+y][j+z]>=0){
                        if( a[i+y][j+z]>=0 &&
                            i+y>0 && i+y<=n &&
                            j+z>0 && j+z<=n
                        ){
                            a[i+y][j+z]=1;
                        }
                        y+=dl_regina[k];
                        z+=dc_regina[k];
                    }
                }
                break;
            case -4:
                for(k=1;k<=4;k++)
                {
                    y=dl_nebun[k];
                    z=dc_nebun[k];
                    while(a[i+y][j+z]>=0){
                        if( a[i+y][j+z]>=0 &&
                            i+y>0 && i+y<=n &&
                            j+z>0 && j+z<=n
                        ){
                            a[i+y][j+z]=1;
                        }
                        y+=dl_nebun[k];
                        z+=dc_nebun[k];
                    }
                }
                break;
            case -5:
                for(k=1;k<=4;k++)
                {
                    y=dl_pion[k];
                    z=dc_pion[k];
                    while(a[i+y][j+z]>=0){
                        if( a[i+y][j+z]>=0 &&
                            i+y>0 && i+y<=n &&
                            j+z>0 && j+z<=n
                        ){
                            a[i+y][j+z]=1;
                        }
                        y+=dl_pion[k];
                        z+=dc_pion[k];
                    }
                }
                break;
            case -6:
                for(k=1;k<=8;k++)
                {
                    if( a[i+dl_cal[k]][j+dc_cal[k]]>=0 &&
                        i+dl_cal[k]>0 && i+dl_cal[k]<=n &&
                        j+dc_cal[k]>0 && j+dc_cal[k]<=n
                    ){
                        a[i+dl_cal[k]][j+dc_cal[k]]=1;
                    }
                }
                break;
        }
    }
    for(x=1;x<=t;x++)
    {
        fin>>i>>j;
        if(a[i][j]<0)
            fout<<"2"<<'\n';
        else
            fout<<a[i][j]<<'\n';
    }
    return 0;
}



