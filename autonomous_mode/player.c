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

void deallocate_players(Player* players, int player_number) {
    for(int i = 0; i < player_number; i++){
        free(players[i].pingu);
    }
    free(players);
};

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

#endif
