#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int n;
float m, k;

int main()
{
    char s[100]; int i;
    strcpy(s,"bacalaureat");
i=strchr(s,'r')-s;
cout<<i+1;
    return 0;
}
