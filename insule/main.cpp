#include <fstream>

using namespace std;

int main()
{
    ifstream fin("insule.in");
    ofstream fout("insule.out");
    int n,m,i,j,a[100][100],aux[100][100];
    int r,g,b;
    int psn,psm,prim=0,ultim=0,C[2][10000];
    int NrDir=4,pn,pm,k;
    int dl[]={-1,0,1,0};
    int dc[]={0,1,0,-1};
    r=0;
    g=0;
    b=0;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            fin>>a[i][j];
            aux[i][j]=0;
        }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(aux[i][j]==0){
                if(a[i][j]!=0){
                        psn=i;
                        psm=j;
                        aux[i][j]=1;
                        prim=0;
                        ultim=0;
                        C[0][0]=psn;
                        C[1][0]=psm;
                        while(prim<=ultim){
                            pn=C[0][prim];
                            pm=C[1][prim];
                            prim++;
                            for(k=0;k<NrDir;k++){
                                if(a[pn+dl[k]][pm+dc[k]]!=0){
                                    aux[pn+dl[k]][pm+dc[k]]=1;
                                    ultim++;
                                    C[0][ultim]=pn+dl[k];
                                    C[1][ultim]=pm+dc[k];
                                }
                            }
                        }
                        if(a[i][j]==1){
                            r++;
                        }else{
                            if(a[i][j]==2){
                                g++;
                            }
                            else b++;
                        }
                }else{
                    aux[i][j]=1;
                }
            }
        }
    fout<<r<<" "<<g<<" "<<b;
    return 0;
}
