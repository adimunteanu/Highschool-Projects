#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

void conversie(char s[200], int v[200])
{
    int i,n,j;
    n=strlen(s)-1;
    for(i = n,j=0;i>=0;i--,j++)
    {
        v[j] = s[i]-'0';
    }
}
void suma(char s1[200],char s2[200])
{
    int x=0,i,j,v1[200],v2[200],v3[201],t=0;//v1-primul sir de caractere convertit in int;v2-al doilea sir de caractere convertit in int;v3-locul unde voi pastra suma lor;
    conversie(s1,v1);
    conversie(s2,v2);
    i=0;//lungimea primului sir de caractere
    j=0;//lugimea celui de al doilea sir de caractere
    while (i<=strlen(s1)-1&&j<=strlen(s2)-1)
    {
        v3[x]=v1[i]+v2[j]+t;
        if(v3[x]>9)
        {
            v3[x]=v3[x]%10;
            t=1;
        }
        else
        {
            t=0;
        }
        x++;
        i++;
        j++;
    }
    if (i>strlen(s1)-1 && j>strlen(s2)-1 && t==1)
    {
        v3[x]=1;
        x++;
    }
    while (i<=strlen(s1)-1)
        {
            v3[x]=v1[i]+t;
            i++;
            x++;
            t=0;
        }
    while (j<=strlen(s2)-1)
        {
            v3[x]=v2[j]+t;
            j++;
            x++;
            t=0;
        }
    for (i=x-1; i>=0; i--)
    {
        cout<<v3[i];
    }
}
int comparare(char a[200], char b[200])
{
    if (strlen(a)>strlen(b))
        return 1;
    else if (strlen(a)<strlen(b))
        return 2;
    else if (strcmp(a,b)>0)
        return 1;
    else if (strcmp(a,b)<0)
        return 2;
    else return 3;
}
int diferenta(char s1[200],char s2[200])
{
    int i,x=0,t=0,v1[200],v2[200],m,n,v3[200];
    conversie (s1,v1);
    conversie (s2,v2);
    if (comparare(s1,s2)==1)
        {
            conversie (s1,v1);
            conversie (s2,v2);
            m=strlen(s1)-1;
            n=strlen(s2)-1;

        }
    else if(comparare(s1,s2)==2)
        {
            conversie (s1,v2);
            conversie (s2,v1);
            n=strlen(s1)-1;
            m=strlen(s2)-1;
        }
    else {cout<<"0";
    return 0;}
    for(i=n;i>=0;i--)
    {
        v3[x]=v1[i]-v2[i]-t;
    if (v3[x]<0)
    {
        v3[x]=v3[x]+10;
        t=1;
            }
    else t=0;
        x++;
    }
        i=m;
    while (i>n&&i<=m)
    {
        v3[x]=v1[i]-t;
        i--;
        t=0;
        x++;
    }
    i=x-1;
    while(v3[i--]!=0);
    i--;
    for(;i>=0;i--)
        {
        cout<<v3[i];
        }
        }

int inmultire (char s1[200], char s2[200])
{   int v1[100],v2[100];
    int v3[200]={0};
    int i,j,x;
    int m = strlen(s1);
    int n = strlen(s2);
    conversie(s1,v1);
    conversie(s2,v2);
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
        {
            v3[i+j] += v2[i]*v1[j];
        }
    }
    for(i = 0;i < n+m;i++)
    {
        x = v3[i]/10;
        v3[i] = v3[i]%10;
        v3[i+1] = v3[i+1] + x;
    }
    for(i = n+m; i>= 0;i--)
    {
        if(v3[i] > 0)
            break;
    }
    for(;i >= 0;i--)
    {
        cout<<v3[i];
    }
    return 0;
}

int main ()
{
    char s1[200],s2[200];
    int x;
    cout<<"Dati numarul 1:";
    cin>>s1;
    cout<<"Dati numarul 2:";
    cin>>s2;
    cout<<"Alegeti o varianta:"<<endl;
    cout<<"1.Suma numerelor:"<<endl;
    cout<<"2.Diferenta numerelor:"<<endl;
    cout<<"3.Inmultirea numerelor:"<<endl;
    cin>>x;
        if (x==1)suma(s1,s2);
        else if (x==2) diferenta(s1,s2);
        else if (x==3) inmultire(s1,s2);
        return 0;

    }
