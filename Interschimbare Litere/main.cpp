#include <iostream>
#include <cstring>

using namespace std;

char a[11];
int n;

int main()
{
    cin.getline(a, 11);
    n = strlen(a);
    int i = 0;
    while(strchr("aeiouAEIOU", a[i]) == NULL && i < n)
        i++;
    int j = n - 1;
    while(strchr("aeiouAEIOU", a[j]) != NULL && j >= 0)
        j--;
    if(i == n || j == -1)
        cout << "IMPOSIBIL";
    else {
        swap(a[i], a[j]);
        cout << a;
    }
    return 0;
}
