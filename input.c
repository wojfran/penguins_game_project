#include <stdio.h>
#include <stdlib.h>
extern int players, penguins;

void set_board_dimensions(int* x, int* y){
    char z, o = NULL;
    while (isdigit(z) == 0){
        printf("Please enter the X dimension of the board, use a integer\n");
        z = getchar();
        *x = z - '0';
        o = getchar();
    }

    z = NULL;
    while (isdigit(z) == 0){
        printf("Please enter the Y dimension of the board, use an integer\n");
        z = getchar();
        *y = z -'0';
    }
};
/*function, which asks players for board dimensions(lenght and width)*/

void set_number_of_players_and_penguins() {
        players, penguins = NULL;

    while (isdigit(players) == 0){
        printf("Please enter the desired number of players, use a integer\n");
        scanf("%d\n", players);
    }

    while (isdigit(penguins) == 0){
        printf("Please enter the desired amount of penguins that each player should have, use an integer\n");
        scanf("%d\n", penguins);
    }
} // used for setting the number of players and penguins

int are_coordinates_valid() {
 return 1;
} // checks if the specified coordinates for a penguin to place are valid

void ask_for_coordinates(){


    if (are_coordinates_valid()){

    } else {

    }
} // this function lets user to enter the coordinates that they want to move

/*
void ask_for_penguin_coordinates(){

    if (does_penguin_belong_to_current_player() && are_coordinates_valid()){

    } else {

    }
} // it supposed to let user to specify coordinates where they want to move their penguins
*/