#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "player.h"
extern int x, y, player_number, penguins, current_player;

void set_board_dimensions(){
    char* z = malloc(3*sizeof(char));

    do {
        printf("Please enter the X dimension of the board, use a integer\n");
        fgets(z, 4, stdin);
        x = atoi(z);
    } while (x == 0);

    do {
        printf("Please enter the Y dimension of the board, use an integer\n");
        fgets(z, 4, stdin);
        y = atoi(z);
    } while (y == 0);

    free(z);
};
/*function, which asks players for board dimensions(lenght and width)*/

void set_number_of_players_and_penguins() {
    char* z = malloc(2*sizeof(char));

     do {
        printf("Please enter the desired number of players, use a integer\n");
        fgets(z, 3, stdin);
        player_number = atoi(z);
    } while (player_number == 0);

    do {
        printf("Please enter the desired amount of penguins that each player should have, use an integer\n");
        fgets(z, 3, stdin);
        penguins = atoi(z);
    } while (penguins == 0);
} // used for setting the number of players and penguins

int are_coordinates_digits() {

} 
// checks if the specified coordinates for a penguin to place are valid

void ask_for_coordinates_to_place_penguin(Player playa){
    printf("Where do you wish to place your penguin Player %d? Please enter integere coordinates:\n", current_player);
    char* z = malloc(3*sizeof(char));

    do {
        printf("Please enter the X dimension of the board, use a integer\n");
        fgets(z, 4, stdin);
        x = atoi(z);
    } while (x == 0);

    do {
        printf("Please enter the Y dimension of the board, use an integer\n");
        fgets(z, 4, stdin);
        y = atoi(z);
    } while (y == 0);

    free(z);
} // this function lets user to enter the coordinates that they want to move

/*
void ask_for_penguin_coordinates(){

    if (does_penguin_belong_to_current_player() && are_coordinates_valid()){

    } else {

    }
} // it supposed to let user to specify coordinates where they want to move their penguins
*/