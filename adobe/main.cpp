#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

char v1[]="eE";
char v2[]="bB";
char v3[]="oO";
char v4[]="dD";
char v5[]="aA";

int t = 0;
char a[100001];


char nr[]="adobe";
char special[]="";
int nr_special = 0;
int p;
int ok1, ok2, ok3, ok4, ok5;

int main()
{
    ifstream fin("eboda.in");



    fin.getline(a,100001);
    fin.get();


    for(int i = 0; i < strlen(a) - 4; i++)
    {
        p = 0;
        for(int j = i; j <= i + 4; j++)
        {
            nr[p] = a[j];
            p++;
        }
        ok1 = 0; ok2 = 0; ok3 = 0; ok4 = 0; ok5 = 0;
        nr_special = 0;

        for(int l = 0; l <= 4; l++)
        {
            if(strchr(v1, nr[l]) > 0) ok1++;
            else if(strchr(v2,nr[l])>0) ok2++;
            else if(strchr(v3,nr[l])>0) ok3++;
            else if(strchr(v4,nr[l])>0) ok4++;
            else if (strchr(v5,nr[l])>0) ok5++;
            else {special[nr_special] = nr[l]; nr_special++;}
        }
        for(int l = 0; l < nr_special; l++)
        {
            switch(special[l]){
                case '+':
                    if(ok2 == 0)
                        ok2++;
                    else
                        if(ok4 == 0)
                            ok4++;
                    break;
                case '-':
                    if(ok1 ==0)
                        ok1++;
                    else
                        if(ok3 == 0)
                            ok3++;
                        else
                            if(ok5 == 0)
                                ok5++;
                    break;
            }
        }
        for(int l = 0; l <= nr_special; l++)
        {
            if(special[l] == '*')
                if(ok1 ==0)
                    ok1++;
                else
                    if(ok2 == 0)
                        ok2++;
                    else
                        if(ok3 == 0)
                            ok3++;
                        else
                            if(ok4 == 0)
                                ok4++;
                            else
                                if(ok5 == 0)
                                    ok5++;
        }
        if(ok1==1 and ok2==1 and ok3==1 and ok4==1 and ok5==1) t++;
    }
    cout<<t;

    return 0;
}
