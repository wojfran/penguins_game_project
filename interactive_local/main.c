#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "input.h"
#include "penguins.h"
#include "player.h"
#include "movement.h"


int x;
int y; // board dimensions, later used to store input coordinates
int rows, columns;
int x_penguin, y_penguin; // storage for chosen penguin coordinates
int player_number; // number of players
int penguins; // number of penguins
int current_penguin = 1;
int current_player = 1; //integer signifying the current player
int score; // keeps score
int counter; // used to count the inability to make a move,
             // once it is equal the number of players the phase is finished

int main(){
    // input phase
    system("clear");
    set_board_dimensions();
    int** board = allocate_memory_for_board(columns, rows);
    generate_board(board);
    display_board(board);

    set_number_of_players_and_penguins();
    printf("\nThose are the global players and penguins values:\n%d\n%d\n", player_number, penguins);
    Player* players = generate_players(player_number, penguins);

    // placement phase
    current_player = 1;
    while(can_any_penguins_be_placed(players)){
        if(check_if_current_players_penguins_can_be_placed(players[current_player-1])){
            system("clear");
            display_board(board);
            ask_for_coordinates_to_place_penguin(players[current_player-1], board);
            place_penguin(players[current_player-1], board);
        } else {
            printf("This should never appear if can any penguins be placed works correctly");
        }
        change_current_player();
    }

    // moving phase
    while(can_any_penguins_move(players, board)){
        //system("clear");
        display_board(board);
        ask_for_penguin_coordinates(players[current_player-1], board);
        ask_for_coordinates_to_move_penguin(players[current_player - 1], board);
        move_penguin(board, players[current_player-1], x_penguin, y_penguin, x, y);
        change_current_player();
    }
    //move_penguin(board, players[0],0,0,4,4);

    display_board(board);
    printf("\nThe game has finished!\n");
    deallocate_players(players, player_number);
    free_board_memory(board, columns);
}