#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("decodificare.in");
ofstream fout("decodificare.out");

char a[10000];
int n;

int main()
{
    fin >> n;
    fin.get();
    fin.getline(a, 10000);

    int increment_first_half = n / 2 - 1;
    int length = strlen(a) - (n / 2);

    for(int i = increment_first_half; i <= length; i += increment_first_half)
        cout << a[i];

    int increment_second_half = n / 2 + 1;

    for(int i = 0; i < strlen(a); i += increment_second_half)
        cout << a[i];
    return 0;
}
