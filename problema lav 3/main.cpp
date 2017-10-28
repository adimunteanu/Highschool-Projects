#include <iostream>
#include <fstream>
using namespace std;
ifstream f("palindrom_ciclic.in");
ofstream g("palindrom_ciclic.out");
void citire(int &n, int a[1001])
{
    f>>n;
    for(int i=1;i<=n;i++) f>>a[i];
}
int verificare(int n, int a[1001])
{
    int i=1;
    int ok=1;
    while(i<=n/2)
    {
        if(a[i]!=a[n-i+1])
            ok=0;
        i++;
    }
    if(ok==1) return 1;
    else return 0;
}
void permutare(int a[1001], int n)
{
    int i;
    int r=a[1];
    for(i=1;i<=n-1;i++) a[i]=a[i+1];
    a[n]=r;
}
void scriere (int r, int ok)
{
    if(ok==1)
    {
        g<<"DA"<<" "<<r;
    }
    if(ok==0)
        g<<"NU";
}
int main()
{
     int a[1001], n;
     citire(n,a);
     int r=0;
     int ok=0;
     int t;
     while(r<=n)
     {

         t=verificare(n,a);
         if(t==1){
            ok = 1;
            break;
         }
         else
         {
             permutare(a,n);
             r++;
         }



     }
     scriere (r,ok);
    return 0;
}
