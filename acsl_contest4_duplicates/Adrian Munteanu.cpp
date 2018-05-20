/*
 Name: Adrian Munteanu
 Date: 3/25/18
 School: Colegiul National "UNIREA"
 Division: Intermediate 5
 ACSL Contest #4
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <algorithm>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct Instruction {
    char instruction[20];
    char data[50];
};

struct ReportedItems{
    int item;
    int reported_val[20];
    int length;
};

int counts[17];
int letters[27];
int length = 0;
int str_int[50];

ReportedItems reported[6];
Instruction instructions[15];
int l_i, l_r = 0;

int read_input()
{
    int i = 0;
    while(!fin.eof()){
        i++;
        fin.getline(instructions[i].instruction, 7,' ');
        fin.getline(instructions[i].data, 40);
        for( int j=0 ; j < strlen(instructions[i].data) ; ++j ) instructions[i].data[j] = toupper( instructions[i].data[j] ) ;
    }
    i--;
    return i;
}

void store_reported_items()
{
    for(int i = 1; i <= l_i; i++)
    {
        if(strcmp(instructions[i].instruction, "REPORT") == 0)
        {
            bool has_not_been_added_before = true;
            for(int j = 1; j <= l_r; j++){
                int z ;
                stringstream(instructions[i].data) >> z;
                if(reported[j].item == z)
                    has_not_been_added_before = false;
            }
            if(has_not_been_added_before){
                l_r++;
                stringstream(instructions[i].data) >> reported[l_r].item;
            }
        }
    }
}

int convert_char_to_int(char str[])
{
    int str_length = 0;
    for(int i = 0; i < strlen(str); i++)
        if(int(str[i]) >= 65){
            str_length++;
            str_int[str_length] = int(str[i]);
        }
    return str_length;
}

void check_if_anything_changed()
{
    for(int i = 1; i <= l_r; i++)
    {
        if(letters[reported[i].item] != reported[i].reported_val[reported[i].length])
        {
            reported[i].length++;
            reported[i].reported_val[reported[i].length] = letters[reported[i].item];
        }
    }
}

void ADD(char str[])
{
    int str_int_length = convert_char_to_int(str);

    for(int i = 1; i <= str_int_length; i++)
    {
        if(length == 0){
            letters[1] = str_int[i];
            check_if_anything_changed();
            counts[1]++;
            length++;
        } else {
            int k = 1;
            while(str_int[i] > letters[k] && k <= length)
                k++;
            if(str_int[i] == letters[k]){
                counts[k]++;
            } else {
                if(str_int[i] < letters[k]){
                    for(int j = length; j >= k; j--){
                        letters[j + 1] = letters[j];
                        counts[j + 1] = counts[j];
                    }
                    letters[k] = str_int[i];
                    check_if_anything_changed();
                    counts[k] = 1;
                    length++;
                } else {
                    if(k == length + 1){
                        letters[k] = str_int[i];
                        check_if_anything_changed();
                        counts[k]++;
                        length++;
                    }
                }
            }
        }
    }
}

void DELETE(char str[])
{
    int str_int_length = convert_char_to_int(str);

    for(int i = 1; i <= str_int_length; i++)
    {
        int k = 1;
        while(str_int[i] != letters[k] && k <= length)
            k++;
        if(str_int[i] == letters[k]){
            if(counts[k] > 1)
                counts[k]--;
            else {
                for(int j = k; j < length; j++){
                    letters[j] = letters[j + 1];
                    counts[j] = counts[j + 1];
                }
                letters[length] = 0;
                counts[length] = 0;
                length--;
                check_if_anything_changed();
            }
        }
    }
}

void RESET(char str[])
{
    for(int i = 1; i <= length; i++){
        counts[i] = 0;
        letters[i] = 0;
    }
    length = 0;

    for(int i = 1; i <= l_r; i++){
        for(int j = 1; j <= reported[i].length; j++)
            reported[i].reported_val[j] = 0;
        reported[i].length = 0;
    }

    ADD(str);
}

void REPORT(int i)
{
    int j = 1;
    int aux;
    stringstream(instructions[i].data) >> aux;
    while(aux != reported[j].item)
        j++;

    for(int k = 1; k <= reported[j].length; k++)
        fout << char(reported[j].reported_val[k]);
    fout << endl;
}

int main()
{
    l_i = read_input() + 1;
    store_reported_items();

    for(int i = 1; i <= l_i; i++)
        if(strcmp(instructions[i].instruction, "RESET") == 0){
            RESET(instructions[i].data);
        } else {
            if(strcmp(instructions[i].instruction, "ADD") == 0){
                ADD(instructions[i].data);
            } else {
                if(strcmp(instructions[i].instruction, "DELETE") == 0){
                    DELETE(instructions[i].data);
                } else {
                    if(strcmp(instructions[i].instruction, "REPORT") == 0){
                        REPORT(i);
                    }
                }
            }
        }
    return 0;
}
