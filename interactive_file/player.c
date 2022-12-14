#ifndef PLAYER_H
#define PLAYER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "penguins.h"
extern int player_number, penguins, current_player, rows, columns;

typedef struct Player {
    char id[25];
    int index;
    int score;
    Penguin* pingu;
} Player;
/*
 Structure Player holds three integers, players which has information about number of
 players, current_player which is signifying the current player and counter which counts the inability of players to
 make a move, once it is equal to number of all players the game ends.
 */

Player create_player(int penguins, char id[25], int index, int score){
    Player player;

    strcpy(player.id, id);
    player.score = score;
    player.index = index;
    player.pingu = malloc(penguins * sizeof(Penguin));

    for (int i = 0; i < penguins; i++) {
        player.pingu[i].x = -1;
        player.pingu[i].y = -1;
    }

    return player;
}

Player* generate_players(int player_number, int penguins) {
    Player* players;
    players = malloc(player_number * sizeof(Player));
    int index = 1;

    for (int i = 0;i < player_number; i++) {
        players[i] = create_player(penguins, "bob", (index+i), 0);
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
        if (playa.pingu[i].x == -1) return 1;  
    }
    return 0;
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

void print_player_penguins_locations(Player playa) {
    for (int i = 0; i < penguins; i++) {
        printf("x: %d, y: %d\n", playa.pingu[i].x+1, playa.pingu[i].y+1);
    }
}

void print_all_players_penguin_coordinates(Player* players) {
    for (int i = 0; i < player_number; i++) {
        printf("The locations of penguins for player with the index: %d is:\n", players[i].index);
        print_player_penguins_locations(players[i]);
    }
}

#endi
