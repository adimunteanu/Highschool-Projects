/*
 Name: Adrian Munteanu
 Date: 2/24/17
 School: Colegiul National "UNIREA"
 Division: Intermediate 5
 ACSL Contest #3
 */
#include <fstream>
#include <string>

using namespace std;


ifstream fin("input.txt");
ofstream fout("output.txt");

string input_line = "", line_hex = " ";

int init_arr[9][9], arr[9][9], l, c, steps, dir;
int output[6][3];
char dir_char;

//Checks if the walker has left the array and sets his location accordingly
void walker_container()
{
    if(l > 8) l = 1;
    if(l < 1) l = 8;
    if(c > 8) c = 1;
    if(c < 1) c = 8;
}

//Converts a single hex digit into binary and returns it as string
string convert_hex_to_binary(char c)
{
    switch(c)
    {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
    }
}

//Converts every hex number into an 8 character long string and then inserts it into the array
void convert_stringline_to_intline(int i) {
    if(line_hex.length() == 2)
        for(int j = 0; j < 2; j++)
            input_line += convert_hex_to_binary(line_hex[j]);
    else
        input_line += "0000" + convert_hex_to_binary(line_hex[0]);

    for(int j = 0; j < input_line.length(); j++)
        if(input_line[j] == '0') init_arr[i][j + 1] = 0;
        else init_arr[i][j + 1] = 1;

    input_line = "";
}

//Reads the array and fills it up with 1s and 0s accordingly
void read_array()
{
    for(int i = 1; i < 8; i++){
        getline(fin, line_hex , ' ');
        convert_stringline_to_intline(i);
    }

    //This code takes the last last hex number and turns it into the last line
    getline(fin, line_hex);
    convert_stringline_to_intline(8);
}

//Reads instructions and turns the direction into an int
void read_instructions()
{
    fin >> l >> c >> dir_char >> steps;

    switch(dir_char){
        case 'L': dir = 1;
            break;
        case 'B': dir = 2;
            break;
        case 'R': dir = 3;
            break;
        case 'A': dir = 4;
            break;
    }
}

//Resets the array to the original one
void reset_array()
{
    for(int i = 1; i <= 8; i++)
        for(int j = 1; j <= 8; j++)
            arr[i][j] = init_arr[i][j];
}

int main()
{
    read_array();
    reset_array(); //Initializes the array we are working with

    //This code is run 5 times, one time for each input
    for(int k = 1; k <= 5; k++)
    {
        read_instructions();
        for(int step_count = 1; step_count <= steps; step_count++)
        {
            if(!arr[l][c]){
                //According to the direction the walker is coming from, he maintains his trajectory
                switch(dir){
                    case 1: c++; break;
                    case 2: l--; break;
                    case 3: c--; break;
                    case 4: l++; break;
                }

                walker_container();

            } else {
                switch(arr[l][c])
                {
                    //First time he enters the square (he takes a left)
                    case 1:
                        arr[l][c]++; //Increases the number of times he has passed through the respective square
                        switch(dir){
                            case 1: l--; dir = 2; break;
                            case 2: c--; dir = 3; break;
                            case 3: l++; dir = 4; break;
                            case 4: c++; dir = 1; break;
                        };
                        break;
                    //Second time he enters the square (he keeps going)
                    case 2:
                        arr[l][c]++;
                        switch(dir){
                            case 1: c++; break;
                            case 2: l--; break;
                            case 3: c--; break;
                            case 4: l++; break;
                        };
                        break;
                    //Third time he enters the square (he takes a right)
                    case 3:
                        arr[l][c]++;
                        switch(dir){
                            case 1: l++; dir = 4; break;
                            case 2: c++; dir = 1; break;
                            case 3: l--; dir = 2; break;
                            case 4: c--; dir = 3; break;
                        };
                        break;
                    //Fourth time he enters the square (he goes back)
                    case 4:
                        arr[l][c] = 1; //This means that the next time he's going to pass through here he will have to take a left (Case 1)
                        switch(dir){
                            case 1: c--; dir = 3; break;
                            case 2: l++; dir = 4; break;
                            case 3: c++; dir = 1; break;
                            case 4: l--; dir = 2; break;
                        };
                        break;
                };

                walker_container();

            }
        }
        reset_array(); // Resets the array for the next input

        //Stores the output
        output[k][1] = l;
        output[k][2] = c;

    }

    //Output
    for(int i = 1; i <= 5; i++)
        fout << output[i][1] << " " << output[i][2] << endl;
    return 0;
}
