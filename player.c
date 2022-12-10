#ifndef PLAYER_H
#define PLAYER_H
#include <stdio.h>
#include <stdlib.h>
#include "penguins.h"
extern int player_number, penguins, current_player, rows, columns;

typedef struct Player {
    int index;
    int score;
    Penguin* pingu;
} Player;
/*
 Structure Player holds three integers, players which has information about number of
 players, current_player which is signifying the current player and counter which counts the inability of players to
 make a move, once it is equal to number of all players the game ends.
 */

Player create_player(int penguins, int index){
    Player player;

    player.score = 0;
    player.index = index;
    player.pingu = malloc(penguins * sizeof(Penguin));

    for (int i = 0; i < penguins; i++) {
        player.pingu[i].flag = 1;
        player.pingu[i].x = 0;
        player.pingu[i].y = 0;
    }

    return player;
}

Player* generate_players(int player_number, int penguins) {
    Player* players;
    players = malloc(player_number * sizeof(Player));
    int index = 1;

    for (int i = 0;i < player_number; i++) {
        players[i] = create_player(penguins, (index+i));
    }

    return players;
}

void deallocate_players(Player* players, int player_number) {
    for(int i = 0; i < player_number; i++){
        free(players[i].pingu);
    }
    free(players);
};

void change_current_player(){
    if (current_player == player_number) {
        current_player = 1;
    } else current_player++;
};
/*
Function that changes current player after his move.
 */

int check_if_current_player_has_penguins_in_hand();
/*
 Checks if current_player - which is equal to 1, has any penguins in hand; outputs 1 or 0.
 */

int check_if_current_players_penguins_can_be_placed(Player playa) {
    int size = sizeof(playa.pingu)/sizeof(playa.pingu[0]);
    for (int i = 0; i < penguins; i++) {
        if (playa.pingu[i].flag == 1) return 1;
    }
};
/*
This function checks if player's penguins have ability to move; outputs 1 or 0.
 */

int does_penguin_belong_to_current_player();
/*
A function that checks if a particular penguin belong to current player; outputs 1 or 0.
 */

void update_score(int player, int score);
/*
 Function which updates score for each particular player.
 */

int can_any_penguins_be_placed(Player* playa) {
    for (int i = 0; i < player_number; i++){
        for (int j = 0; j < penguins; j++){
            if (playa[i].pingu[j].flag == 1) return 1;
        }
    }

    return 0;
};
/*
Checks if any of the created penguins objects has a tile next to them to 
which it can move
*/

/*

int check_if_penguin_can_move(int** board, int x, int y){

        if (x == 0 && y == 0) {
            if (board[y+1][x] > 0 || board[y][x+1] > 0) {
                return 1;
            }
        } else if (x == 0 && y == rows - 1) {
            if (board[y][x+1] > 0 || board[y-1][x] > 0) {
                return 0;
            }
        } else if (x == columns - 1 && y == 0) {
            if (board[y][x-1] > 0 || board[y+1][x] > 0) {
                return 1;
            }
        } else if (x == columns - 1 && y == rows - 1) {
            if (board[y][x-1] > 0 || board[y-1][x] > 0) {
                return 1;
            }
        } else if (x == 0) {
            if (board[y][x+1] > 0 || board[y+1][x] > 0 || board[y-1][x] > 0) {
                return 1;
            }
        } else if (y == 0) {
            if (board[y][x+1] > 0 || board[y][x-1] > 0 || board[y+1][x] > 0) {          
                return 1;
            }
        } else if (x == columns - 1) {   
            if (board[y][x-1] > 0 || board[y-1][x] > 0 || board[y+1][x] > 0) {
                return 1;
            }
        } else if (y == rows - 1) {
            if (board[y-1][x] > 0 || board[y][x-1] > 0 || board[y][x+1] > 0) {
                return 1;
            }
        } else {
            if (board[y+1][x] > 0 || board[y-1][x] > 0 || board[y][x+1] > 0 || board[y][x-1] > 0) {
                return 1;
            } else {
                return 0;
            }
        }
}
*/
#endif