#include <fstream>
#include <cstring>

using namespace std;

int sol[20];
char sir[20];

ifstream fin("anagrame1.in");
ofstream fout("anagrame1.out");

void afisare()
{
    for(int i = 0; i < strlen(sir); i++)
        fout << sir[sol[i]];
    fout << "\n";
}

int ok(int k)
{
    for(int i = 0; i < k ; i++)
        if(sir[sol[k]] == sir[sol[i]])
            return 0;
    return 1;
}

void backtrack(int k)
{
    if(k == strlen(sir))
        afisare();
    else
        for(int i = 0; i < strlen(sir); i++)
        {
            sol[k] = i;
            if(ok(k))
                backtrack(k + 1);
        }
}

int main()
{
    fin.getline(sir, 8);
    for(int i = 0; i < strlen(sir) - 1; i++)
        for(int j = i + 1; j < strlen(sir); j++)
            if(sir[i] > sir[j])
                swap(sir[i], sir[j]);
    backtrack(0);
    return 0;
}
