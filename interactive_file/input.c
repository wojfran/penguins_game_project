#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Player.h"
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
} // used for setting the number of players and penguins

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
    //system("clear");
} // this function lets user to enter the coordinates that they want to move

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
} // it supposed to let user to specify coordinates where they want to move their penguins

int check_if_penguin_belongs_to_player(int** board, Player playa, int x, int y){
    int penguin_index = (board[y][x]/100);
    int player_index = (board[y][x]%10);

    if (board[y][x] < 4 && board[y][x] > 0) {
        getchar();
        printf("\nYou can't move the fish silly! Please pick again\n");
        return 0;
    } else if (board[y][x] == 0) {
        getchar();
        printf("\nThis tile contains only cold water silly! Please pick again\n");
        return 0;
    } else if (playa.index != player_index){
        getchar();
        printf("\nYou picked the wrong player silly! Please pick again\n");
        return 0;
    } else {
        return 1;
    }
}

int check_if_coordinate_matches_board(int b_dimension, int x) {
    if (x < 1 || x > b_dimension) {
        getchar();
        printf("\nGiven coordinate doesn't match the board dimensions silly! Please pick again\n");
        return 0;
    } else {
        return 1;
    }
};

int check_if_given_dimension_is_ok(int x){
    if (x < 2 || x > 99){
        getchar();
        printf("\nWrong dimension silly! It should be an integer greater than 1 and smaller than 99. Please pick again\n\n");
        return 0;
    } else {
        return 1;
    }
};

int check_if_ice_has_fish(int** board, int x, int y) {
    if ((board[y-1][x-1] / 10) > 0 && (board[y-1][x-1] / 10) < 4 && (board[y-1][x-1] % 10 == 0)) {
        return 1;
    } else if (board[y-1][x-1] == 0) {
        getchar();
        printf("\nThis ice floe doesn't have any fish silly! Please pick again\n");
        return 0;
    } else if(board[y-1][x-1] % 10 != 0) {
        getchar();
        printf("\nThis ice floe is already occupied by a penguin, you can't move here silly! Please pick again\n");
        return 0;
    }
}

int check_if_number_of_players_or_penguins_correct(int num) {
    if (num < 5 && num > 0) {
        return 1;
    } else {
        getchar();
        printf("\nThe number you entered is not allowed silly! Please pick something in the range 1-4\n");
        return 0;
    }
}

int check_if_penguin_is_not_flying(int x_penguin, int y_penguin, int x, int y) {
    x_penguin++;
    y_penguin++;

    int delta_x = x - x_penguin;
    int delta_y = y - y_penguin;

    if (delta_x == 1 && delta_y == 0) {
        return 1;
    } else if (delta_x == 0 && delta_y == 1) {
        return 1;
    } else if (delta_x == -1 && delta_y == 0) {
        return 1;
    } else if (delta_x == 0 && delta_y == -1) {
        return 1;
    } else {
        printf("\nPenguins can't fly silly! Please pick an ice floe to next to your penguin (not diagonal though)\n");
        return 0;
    }
}

int check_if_penguin_can_move(int** board, int x_penguin, int y_penguin) {
    int x = x_penguin + 1;
    int y = y_penguin + 1;

    /*printf("Columns: %d\n", columns);
    printf("Rows: %d\n", rows);
    printf("Xp: %d\n", x_penguin);
    printf("Yp: %d\n", y_penguin);
    printf("X: %d\n", x);
    printf("Y: %d\n", y);
    */ // diagnostic prints

    if (x > 1 && x < columns && y > 1 && y < rows) {
        if (board[y-1][x] > 0 && board[y-1][x] < 4) {
            //printf("d");
            return 1;
        } else if (board[y][x-1] > 0 && board[y][x-1] < 4) { 
            //printf("s");
            return 1;
        } else if (board[y-1][x-2] > 0 && board[y-1][x-2] < 4) {
            //printf("a");
            return 1;
        } else if (board[y-2][x-1] > 0 && board[y-2][x-1] < 4) {
            //printf("w");
            return 1;
        } else {
            printf("\nThis penguin can't move silly! Please pick a different penguin!\n");
            return 0;
        }
    } else if (x == 1 && y == 1) {
        if (board[y-1][x] > 0 && board[y-1][x] < 4) {
            //printf("d1");
            return 1;
        } else if (board[y][x-1] > 0 && board[y][x-1] < 4) { 
            //printf("s1");
            return 1;
        } else {
            printf("\nThis penguin can't move silly! Please pick a different penguin!\n");
            return 0;
        }
    } else if (x == columns && y == rows) {
        if (board[y-1][x-2] > 0 && board[y-1][x-2] < 4) {
            //printf("a2");
            return 1;
        } else if (board[y-2][x-1] > 0 && board[y-2][x-1] < 4) {
            //printf("w2");
            return 1;
        } else {
            printf("\nThis penguin can't move silly! Please pick a different penguin!\n");
            return 0;
        }
    } else if (x == 1 && y == rows) {
        if (board[y-1][x] > 0 && board[y-1][x] < 4) {
            //printf("d3");
            return 1;
        } else if (board[y-2][x-1] > 0 && board[y-2][x-1] < 4) {
            //printf("w3");
            return 1;
        } else {
            printf("\nThis penguin can't move silly! Please pick a different penguin!\n");
            return 0;
        }
    } else if (x == columns && y == 1) {
        if (board[y-1][x-2] > 0 && board[y-1][x-2] < 4) {
            //printf("a4");
            return 1;
        } else if (board[y][x-1] > 0 && board[y][x-1] < 4) {
            //printf("s4");
            return 1;
        } else {
            printf("\nThis penguin can't move silly! Please pick a different penguin!\n");
            return 0;
        }
    } else if (x == 1 && y > 1 && y < rows) {
        if (board[y-2][x-1] > 0 && board[y-2][x-1] < 4) {
            //printf("w5");
            return 1;
        } else if (board[y][x-1] > 0 && board[y][x-1] < 4) {
            //printf("s5");
            return 1;
        } else if (board[y-1][x] > 0 && board[y-1][x] < 4) {
            //printf("d5");
            return 1;
        } else {
            printf("\nThis penguin can't move silly! Please pick a different penguin!\n");
            return 0;
        }
    } else if (x == columns && y > 1 && y < rows) {
        if (board[y-2][x-1] > 0 && board[y-2][x-1] < 4) {
            //printf("w6");
            return 1;
        } else if (board[y][x-1] > 0 && board[y][x-1] < 4) {
            //printf("s6");
            return 1;
        } else if (board[y-1][x-2] > 0 && board[y-1][x-2] < 4) {
            //printf("a6");
            return 1;
        } else {
            printf("\nThis penguin can't move silly! Please pick a different penguin!\n");
            return 0;
        }
    } else if (x > 1 && x < columns && y == 1) {
        if (board[y-1][x-2] > 0 && board[y-1][x-2] < 4) {
            //printf("a7");
            return 1;
        } else if (board[y][x-1] > 0 && board[y][x-1] < 4) {
            //printf("s7");
            return 1;
        } else if (board[y-1][x] > 0 && board[y-1][x] < 4) {
            //printf("d7");
            return 1;
        } else {
            printf("\nThis penguin can't move silly! Please pick a different penguin!\n");
            return 0;
        }
    } else if (x > 1 && x < columns && y == rows) {
        if (board[y-1][x-2] > 0 && board[y-1][x-2] < 4) {
            //printf("a7");
            return 1;
        } else if (board[y-2][x-1] > 0 && board[y-2][x-1] < 4) {
            //printf("w7");
            return 1;
        } else if (board[y-1][x] > 0 && board[y-1][x] < 4) {
            //printf("d7");
            return 1;
        } else {
            printf("\nThis penguin can't move silly! Please pick a different penguin!\n");
            return 0;
        }
    } else {
        printf("\nUnknown Situation\n");
        return 1;
    }
}; 

int can_any_penguins_move(Player* playa, int** board){
    for (int i = 0; i < player_number; i++){
        for (int j = 0; j < penguins; j++){
            int x = playa[i].pingu[j].x;
            int y = playa[i].pingu[j].y;
            
            if(check_if_penguin_can_move(board, x, y)){
                return 1;
            } else {
                system("clear");
                return 0;
            }
        }
    }
    printf("here");
    return 0;
};