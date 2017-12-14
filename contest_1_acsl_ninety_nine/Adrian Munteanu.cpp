#include <iostream>

using namespace std;


int total_points;
bool turn = true; // player = true, dealer = false
char x[1];

int player_hand[4];
int pile[8];
int output[6][3], output_index = 1;

void turn_cards_to_numbers(int arr[], int arr_size)
{
    for(int i = 1; i <= arr_size; i++){
        cin >> x;
        switch(x[0]){
            case 'T':
                arr[i] = 10;
                break;
            case 'J':
                arr[i] = 11;
                break;
            case 'Q':
                arr[i] = 12;
                break;
            case 'K':
                arr[i] = 13;
                break;
            case 'A':
                arr[i] = 14;
                break;
            default:
                arr[i] = x[0] - 48;
        }
    }
}

void read_input()
{
    cin >> total_points;
    turn_cards_to_numbers(player_hand , 3);
    turn_cards_to_numbers(pile, 7);
}

void place_down_card(int card)
{
    switch(card){
        case 9:
            total_points += 0;
            break;
        case 10:
            total_points -= 10;
            break;
        case 14:
            if(total_points + 14 > 99)
                total_points ++;
            else
                total_points += 14;
            break;
        default:
            total_points += card;
    }
}


int main()
{
    for(int k = 1; k <= 5; k++){
        read_input();

        turn = true;
        int pile_index = 1;

        while(total_points < 100){
            if(turn){
                int maximum = player_hand[1];
                int maximum_index = 1;
                for(int i = 2; i <= 3; i++)
                    if(maximum < player_hand[i]){
                        maximum = player_hand[i];
                        maximum_index = i;
                    }

                place_down_card(maximum);

                player_hand[maximum_index] = pile[pile_index];
                pile_index++;
                turn = false;
            } else {
                place_down_card(pile[pile_index]);
                pile_index ++;

                turn = true;
            }
        }

        output[output_index][1] = total_points;

        if(turn){
            output[output_index][2] = 1;
            output_index ++;
        } else {
            output_index ++;
        }
    }

    for(int i = 1; i <= 5; i++){
        cout << output[i][1] << " ";
        if(output[i][2])
            cout << "player";
        else
            cout << "dealer";
        cout << '\n';
    }

    return 0;
}
