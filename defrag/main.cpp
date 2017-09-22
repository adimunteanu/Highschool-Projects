#include <fstream>

using namespace std;

int a[101][361];

int main()
{
    ifstream fin("defrag.in");
    ofstream fout("defrag.out");
    int p,s,c,i,j,v,x,y,ok,k,so,min;
    fin>>v;
    fin>>p>>s;
    fin>>c;
    for(i=1;i<=c;i++)
    {
        fin>>x>>y;
        a[x][y]=1;
        a[x][0]++;
    }
    if(v==1){
        x=0;
        for(i=1;i<=p;i++)
            if(a[i][0]==0) x++;
        fout<<p-x;
    }else{
        for(i=1;i<=p;i++)
        {
            min=s;
            so=a[i][0];
            // j = pozitie inceput de secventa
            for(j=1;j<=s;j++)
            {
                s=0;
                for(k=j;k<j+so;k++)
                    if (a[i][k]==0) s++;
                if (s<min) min=s;
            }
            fout<<min<<" ";
        }
    }
    return 0;
}
