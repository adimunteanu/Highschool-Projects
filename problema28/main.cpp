#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int main()
{
    char a[255][20];
    int n=1,i,j,max=0;
    ifstream fin("bac.txt");
    while(fin.getline(a[n],20)){
        n++;
    }
    n--;
    for(i=1;i<=n;i++){
        if(strlen(a[i])>max){
            max=strlen(a[i]);
        }
    }
    j=0;
    for(i=1;i<=n;i++){
        if(strlen(a[i])==max){
            j++;
        }
    }
    cout<<max<<" "<<j;
    return 0;
}
