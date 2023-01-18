#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Player.h"
#include "checks.h"
extern int x, y, columns, rows, player_number, penguins, current_player, x_penguin, y_penguin;

void set_board_dimensions(){
    do {
        printf("Please enter the X dimension of the board, use a integer\n");
        scanf("%d", &columns);
    } while (!check_if_given_dimension_is_ok(columns));

    do {
        printf("\nPlease enter the Y dimension of the board, use an integer\n");
        scanf("%d", &rows);
    } while (!check_if_given_dimension_is_ok(rows));
};

void set_number_of_players_and_penguins() {
    do {
        printf("\nPlease enter the desired number of players, use a integer\n");
        scanf("%d", &player_number);
    } while (!check_if_number_of_players_or_penguins_correct(player_number));

    do {
        printf("\nPlease enter the desired amount of penguins that each player should have, use an integer\n");
        scanf("%d", &penguins);
    } while (!check_if_number_of_players_or_penguins_correct(penguins));

    system("clear");
}

void ask_for_coordinates_to_place_penguin(Player playa, int** board){
    printf("\nWhere do you wish to place your penguin Player %d? Please enter integer coordinates:", current_player);

    do {
        do {
            printf("\nPlease enter the X dimension of the board, use a integer\n");
            scanf("%d", &x);
        } while (!check_if_coordinate_matches_board(columns, x));

        do {
            printf("\nPlease enter the Y dimension of the board, use an integer\n");
            scanf("%d", &y);
        } while (!check_if_coordinate_matches_board(rows, y));
    } while(!check_if_ice_has_fish(board, x, y));
}

void ask_for_penguin_coordinates(Player playa, int** board){
    printf("\nWhich penguin do you wish to move Player %d? Please enter integer coordinates:", current_player);
    do {
        do {
            printf("\nPlease enter the X location of your penguin, use a integer\n");
            scanf("%d", &x_penguin);
        } while (!check_if_coordinate_matches_board(columns, x_penguin));
        x_penguin--;

        do {
            printf("\nPlease enter the Y location of your penguin, use an integer\n");
            scanf("%d", &y_penguin);
        } while (!check_if_coordinate_matches_board(rows, y_penguin));
        y_penguin--;
    } while(!check_if_penguin_belongs_to_player(board, playa, x_penguin, y_penguin) || !check_if_penguin_can_move(board, x_penguin, y_penguin));
}

void ask_for_coordinates_to_move_penguin(Player playa, int** board){
    printf("\nWhere do you wish to move your penguin Player %d? Please enter integer coordinates:", current_player);

    do {
        do {
            printf("\nPlease enter the X dimension of the board, use a integer\n");
            scanf("%d", &x);
        } while (!check_if_coordinate_matches_board(columns, x));

        do {
            printf("\nPlease enter the Y dimension of the board, use an integer\n");
            scanf("%d", &y);
        } while (!check_if_coordinate_matches_board(rows, y));
    } while(!check_if_ice_has_fish(board, x, y) || !check_if_penguin_is_not_flying(x_penguin, y_penguin, x, y));
    //system("clear");
}
