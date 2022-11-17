#include <stdio.h>
#include <stdlib.h>
#include "penguins.h"
#include "board.h"
#include "input.h"
#include "player.h"

int x, y; // board dimensions, later used to store input coordinates
int x_penguin, y_penguin; // storage for chosen penguin coordinates
int players; // numeber of players
int current_player = 1; //integer signifying the current player
int score; // keeps score
int counter; // used to count the inability to make a move,
             // once it is equal the number of players the phase is finished

int main(){
    input_board_dimensions();
    input_number_of_players_and_penguins();
    generate_board();
    
    // placement phase:
    while(can_any_penguins_be_placed()){
        if (check_if_current_player_has_penguins_in_hand() && check_if_space_on_the_board()){
            show_board();
            ask_for_coordinates();
            struct Penguin penguin1;
            place_penguin(x, y);
            update_score(current_player, score);
            update_board();
            change_current_player(current_player);
        } else {
            change_current_player(current_player);
        }
    }

    // movement phase:
    // WIP
    while(can_any_penguins_move()){
        if (check_if_current_players_penguins_can_move){
            show_board();
            ask_for_penguin_coordinates();
            ask_for_coordinates();
            move_penguin(penguin1, x, y);
            update_score(current_player, score);
            update_board();
            change_current_player(current_player);
        } else {
            change_current_player(current_player);
        }
    }
}