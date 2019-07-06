#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("parole.in");
ofstream fout("parole.out");

char a[52];
char special[] = ".,?!;:_@#";
int n, nr = 0;

int main()
{
    fin >> n;
    fin.get();
    for(int i = 1; i <= n; i++)
    {
        fin.getline(a, 52);
        if(strlen(a) >= 8)
        {
            bool hasLowerCase = false, hasUpperCase = false, hasDigit = false, hasSpecial = false;
            for(int j = 0; j < strlen(a); j++)
            {
                if('a' <= a[j] && a[j] <= 'z')
                    hasLowerCase = true;
                if('A' <= a[j] && a[j] <= 'Z')
                    hasUpperCase = true;
                if('0' <= a[j] && a[j] <= '9')
                    hasDigit = true;
                if(strchr(special, a[j]) != NULL)
                    hasSpecial = true;
            }
            if(hasLowerCase && hasUpperCase && hasDigit && hasSpecial)
                nr++;
        }
    }
    fout << nr;
    return 0;
}
