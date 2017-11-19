#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

int sol[20];
int string_memory_length = 0, n;
char sir[12], string_memory[362880][12];

ifstream fin("permrep.in");
ofstream fout("permrep.out");

void afisare()
{
    int i;
    if(string_memory_length == 0){
        string_memory_length++;
        for(int j = 0; j < n; j++)
            string_memory[string_memory_length][j] = sir[sol[j]];
        for(int k = 0; k < n; k++)
            fout << sir[sol[k]];
        fout << "\n";
    } else {
        bool big_equal = false;
        for(i = 1; i <= string_memory_length; i++){
            bool equals = true;
            for(int j = 0; j < n; j++)
                if(sir[sol[j]] != string_memory[i][j])
                    equals = false;
            if(equals){
                big_equal = true;
                break;
            }
        }
        if((i -1 == string_memory_length) && (!big_equal))
        {
            string_memory_length++;
            for(int j = 0; j < n; j++)
                string_memory[string_memory_length][j] = sir[sol[j]];
            for(int k = 0; k < n; k++)
                fout << sir[sol[k]];
            fout << "\n";
        }
    }


}

int ok(int k)
{
    for(int i = 0; i < k ; i++)
        if(sol[k] == sol[i])
            return 0;
    return 1;
}

void backtrack(int k)
{
    if(k == n)
        afisare();
    else
        for(int i = 0; i < n; i++)
        {
            sol[k] = i;
            if(ok(k))
                backtrack(k + 1);
        }
}

int main()
{
    fin.getline(sir, 11);
    n = strlen(sir);
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if(sir[i] > sir[j])
                swap(sir[i], sir[j]);
    backtrack(0);
    return 0;
}
