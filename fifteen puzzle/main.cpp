#include <bits/stdc++.h>

using namespace std;

char in[120];
int ii , jj;

ifstream fin("input.txt");

int main()
{
    for(int index = 1; index <= 10; index++)
    {
        int poz;
        fin >> poz >> in;

        if(poz % 4 == 0) {
            jj = 4;
            ii = poz / 4;
        } else {
            jj = poz % 4;
            ii = poz / 4 + 1;
        }
        for(int strIndex = 0; strIndex < strlen(in); strIndex++)
            switch(in[strIndex])
            {
                case 'R':
                    jj++;
                    break;
                case 'L':
                    jj--;
                    break;
                case 'A':
                    ii--;
                    break;
                case 'B':
                    ii++;
                    break;
            }
        cout << 4 * (ii - 1) + jj << endl;
    }
    return 0;
}
