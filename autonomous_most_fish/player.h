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
/* Creates players to be used on the board. */

Player* generate_players(int players, int penguins);
/* Function generate_players allocates dynamically memory for the players and generates them. */

void deallocate_players(Player* players, int player_number);
/*This function deallocates memory of before allocated players. */
void change_current_player();
/*
Function that changes current player after his move.
 */

int check_if_current_players_penguins_can_be_placed(Player playa);
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

int can_any_penguins_be_placed(Player* playa);
/*
Used in the placement phase, checks if any player still can place a penguin
according to the input penguin number
*/

void print_all_players_penguin_coordinates(Player* players);
#endif
