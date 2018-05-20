#include <fstream>

using namespace std;

int table[10][10];
ifstream fin ("sudoku.in");
ofstream fout("sudoku.out");

class Empty_fields{
    public:
        int lin[81];
        int col[81];
};

bool ITS_OVER = false;

Empty_fields spaces;
int nr_spaces = 0;

int ok(int k)
{
    int x = spaces.lin[k];
    int y = spaces.col[k];
    for(int i = 1; i <= 9; i++)
        if((i != x && table[x][y] == table[i][y]) || (i != y && table[x][y] == table[x][i]))
            return 0;
    return 1;
}

void backtrack(int k)
{
    if(k == nr_spaces + 1)
        {
            for(int i = 1; i <= 9; i++){
                for(int j = 1; j <= 9; j++)
                    fout << table[i][j] << " ";
                fout << endl;
            }
            ITS_OVER = true;
        }
    else
            for(int i = 1; i <= 9; i++)
            {
                table[spaces.lin[k]][spaces.col[k]] = i;
                if(ok(k)){
                    backtrack(k + 1);
                    table[spaces.lin[k]][spaces.col[k]] = 0;
                }
            }
}

int main()
{
    for(int i = 1; i <= 9; i++)
        for(int j = 1; j <= 9; j++){
            fin >> table[i][j];
            if(table[i][j] == 0){
                nr_spaces ++;
                spaces.lin[nr_spaces] = i;
                spaces.col[nr_spaces] = j;
            }
        }
    backtrack(1);
    return 0;
}
