#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

char eq[20] = "";
int output[6][10];

int round_open;
int round_open_i;

int round_closed;
int round_closed_i;

int square_open;
int square_open_i;

int square_closed;
int square_closed_i;


int is_operator(char x){
    switch(x){
        case '*':
            return 1;
        case '+':
            return 1;
        case '–':
            return 1;
        case '/':
            return 1;
        case 45:
            return 1;
        default:
            return 0;
    }
}

void read_input()
{
    eq[0] = '\0';
    cin.getline(eq, 100);
}

int main()
{
    for(int k = 1; k <= 5; k++){
        read_input();
        int output_index = 0;
        int l = strlen(eq);
        for(int i = 0; i < l; i++)
            switch(eq[i])
            {
                case '[':
                    square_open++;
                    square_open_i = i;
                    break;
                case ']':
                    square_closed++;
                    square_closed_i = i;
                    break;
                case '(':
                    round_open++;
                    round_open_i = i;
                    break;
                case ')':
                    round_closed++;
                    round_closed_i = i;
                    break;
            }

        if(square_closed + square_open == 2)
        {
            if(round_open == 1)
            {
                for(int i = round_open_i + 3; i < square_closed_i; i++)
                    if(isdigit(eq[i]) && !isdigit(eq[i + 1]))
                        if(isdigit(eq[i - 1])){
                            if(is_operator(eq[i - 2])){
                                output_index++;
                                output[k][output_index] = i + 2;
                            }
                        } else{
                            if(is_operator(eq[i - 1])){
                                output_index++;
                                output[k][output_index] = i + 2;
                            }
                        }
            } else {
                for(int i = square_open_i + 1;  i <= round_closed_i - 3; i++)
                    if(isdigit(eq[i]) && !isdigit(eq[i - 1]))
                        if(isdigit(eq[i + 1])){
                            if(is_operator(eq[i + 2])){
                                output_index++;
                                output[k][output_index] = i + 1;
                            }
                        } else{
                            if(is_operator(eq[i + 1])){
                                output_index++;
                                output[k][output_index] = i + 1;
                            }
                        }
            }
        } else {
            if(square_open){
                for(int i = round_closed_i;  i < l; i++)
                    if(is_operator(eq[i + 1]) || i == l - 1){
                        output_index++;
                        output[k][output_index] = i + 2;
                    }
            } else {
                if(square_closed){
                    for(int i = 0; i <= round_open_i; i++)
                        if(i == 0 || is_operator(eq[i - 1])){
                            output_index++;
                            output[k][output_index] = i + 1;
                        }
                } else {
                    if(round_open){
                        for(int i = round_open + 3; i < l; i++)
                            if(is_operator(eq[i + 1]) || i == l - 1){
                                output_index++;
                                output[k][output_index] = i + 2;
                            }
                    } else {
                        for(int i = 0; i <= round_closed_i - 3; i++)
                            if(i == 0 || is_operator(eq[i - 1])){
                                output_index++;
                                output[k][output_index] = i + 1;
                            }
                    }
                }
            }
        }

        round_open = 0;
        round_open_i = 0;

        round_closed = 0;
        round_closed_i = 0;

        square_open = 0;
        square_open_i = 0;

        square_closed = 0;
        square_closed_i = 0;
    }

    for(int i = 1; i <= 5; i++)
    {
        cout << endl;
        for(int j = 1; j <= 9; j++)
            if(output[i][j] != 0)
                cout << output[i][j] << " ";
    }
    return 0;
}
