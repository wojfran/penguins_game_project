#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "player.h"
extern int x, y, columns, rows, player_number, penguins, current_player, x_penguin, y_penguin;

void set_board_dimensions(){
    char* z = malloc(3*sizeof(char));

    do {
        printf("Please enter the X dimension of the board, use a integer\n");
        fgets(z, 3, stdin);
        columns = atoi(z);
    } while (columns == 0);

    do {
        printf("Please enter the Y dimension of the board, use an integer\n");
        fgets(z, 3, stdin);
        rows = atoi(z);
    } while (rows == 0);

    system("clear");
    free(z);
};
/*function, which asks players for board dimensions(lenght and width)*/

void set_number_of_players_and_penguins() {
    char* z = malloc(3*sizeof(char));

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

    system("clear");
} // used for setting the number of players and penguins

void ask_for_coordinates_to_place_penguin(Player playa){
    printf("Where do you wish to place your penguin Player %d? Please enter integer coordinates:\n", current_player);
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

    system("clear");
    free(z);
} // this function lets user to enter the coordinates that they want to move
/*
void ask_for_penguin_id(Player playa){
    printf("Which penguin do you pick Player %d? Please enter integer coordinates:\n", current_player);
    char* z = malloc(2*sizeof(char));

    do {
        printf("Please enter the index of the penguin (ranging from 1 to the number of penguins chosen)\n");
        fgets(z, 2, stdin);
        current_penguin = atoi(z);
    } while (x == 0 || x > penguins || x < 1);

    system("clear");
    free(z);
}
*/
void ask_for_penguin_coordinates(Player playa, int** board){
    printf("Which penguin do you wish to move Player %d? Please enter integer coordinates:\n", current_player);
    char* z = malloc(3*sizeof(char));

    do{
        do {
            printf("Please enter the X location of your penguin, use a integer\n");
            fgets(z, 3, stdin);
            x_penguin = atoi(z);
        } while (x_penguin == 0);
        x_penguin--;

        do {
            printf("Please enter the Y location of your penguin, use an integer\n");
            fgets(z, 3, stdin);
            y_penguin = atoi(z);
        } while (y_penguin == 0);
        y_penguin--;

    }while (are_coordinates_valid(board, playa, x_penguin, y_penguin));

    //system("clear");
    free(z);
} // it supposed to let user to specify coordinates where they want to move their penguins

int are_coordinates_valid(int** board, Player playa, int x, int y){
    int penguin_index = (board[x][y]/100);
    int player_index = (board[x][y]%10);

    if (playa.index != player_index){
        printf("wrong player!\n");
        return 1;
    } else return 0;
}