#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int sol[20], n;
bool keep_running = true;
ifstream fin("regine1.in");
ofstream fout("regine1.out");

void afisare()
{
    int p = n;
    for(int j = 1; j <= n; j++){
        for(int i = 1; i <=n ; i++)
            if(sol[i] == p){
                cout << "*" << " ";
            }
            else
                cout << "-" << " ";
        p--;
        cout << endl;
    }
}

int ok(int k)
{
    for(int i = 1; i < k ; i++)
        if((sol[k] == sol[i]) || (abs(i - k) == abs(sol[k] - sol[i]) ) )
            return 0;
    return 1;
}

void backtrack(int k)
{
    if(k == n + 1){
        afisare();
        keep_running = false;
    }
    else
        if(keep_running){
            for(int i = 1; i <= n; i++)
            {
                sol[k] = i;
                if(ok(k))
                    backtrack(k + 1);
            }
        }4
}

int main()
{
    cin >> n;
    backtrack(1);
    return 0;
}
