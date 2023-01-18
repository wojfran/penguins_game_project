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

void display_score_of_players(Player* players, int player_number) {
    printf("-----------Scoreboard-----------\n");
    for(int i = 0; i < player_number; i++){
        printf("The score of the player with index [%d] is: %d\n", players[i].index, players[i].score);
    }
}

#endif