#ifndef PLAYER_H
#define PLAYER_H
#include "penguins.h"
extern int player_number, penguins, current_player;

typedef struct Player {
    char id[25];
    int index;
    int score;
    Penguin* pingu;
} Player;
/*
Structure representing a player/team taking part in the game. It hold the following attributes:
    - char id[25], this is the name of the player/team
    - int index, this is the index of the player/team, no two players/teams can have the same index
    - int score, self-explanatory, it holds the current score of the player/team
    - Penguin* pingu, a dynamic array of Penguin structures, representing the penguins
    belonging to the player, its size is the amount of penguins chosen at the start of the game
*/

Player create_player(int penguins, char id[25], int index, int score);
/* 
Creates players to be used on the board. 
It allocates memory for the Penguins* pingu dynamic array according to the 
amount of penguisn chosen at the beginning of the game (stored in int penguins). 
*/

void deallocate_players(Player* players, int player_number);
/*
This function deallocates the memory from the dynamic array of Player structures
given as a parameter called players. The other parameter int player_number tells
the function the size of the given array.
*/

void print_player_penguins_locations(Player playa);
/*
This function prints the location i.e. coordinates of the penguins belonging to the
given player in the convention of indexing starting from 1.
*/

void print_all_players_penguin_coordinates(Player* players);
/*
An expanded version of the function print_player_penguins_locations(Player playa). It 
prints the coordinates of the penguins of all players stored in the given dynamic array
of Player structure objects.
*/

#endif
