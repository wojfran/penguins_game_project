#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "input.h"
#include "penguins.h"
#include "player.h"


int x;
int y; // board dimensions, later used to store input coordinates
int x_penguin, y_penguin; // storage for chosen penguin coordinates
int player_number; // number of players
int penguins; // number of penguins
int current_player = 1; //integer signifying the current player
int score; // keeps score
int counter; // used to count the inability to make a move,
             // once it is equal the number of players the phase is finished

int main(){
    // input phase
    set_board_dimensions(&x, &y);
    printf("\nThose are the global x and y values:\n%d\n%d\n", x, y);
    
    int** board = allocate_memory_for_board(x, y);
    generate_board(board);
    display_board(board);

    set_number_of_players_and_penguins();
    printf("\nThose are the global players and penguins values:\n%d\n%d\n", player_number, penguins);
    Player* players = generate_players(player_number, penguins);

    // placement phase
    while(can_any_penguins_be_placed(players)){
        break;
    }

    deallocate_players(players, player_number);
    free_board_memory(board, x);
}