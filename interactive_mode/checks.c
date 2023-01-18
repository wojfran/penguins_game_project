#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Player.h"
#include "checks.h"
extern int x, y, columns, rows, player_number, penguins, current_player, x_penguin, y_penguin;

extern int columns, rows;

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
    if (board[y-1][x-1] > 0 && board[y-1][x-1] < 4) {
        return 1;
    } else if (board[y-1][x-1] == 0) {
        getchar();
        printf("\nThis ice floe doesn't have any fish silly! Please pick again\n");
        return 0;
    } else if(board[y-1][x-1] > 3) {
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

int check_if_current_players_penguins_can_be_placed(Player playa) {
    int size = sizeof(playa.pingu)/sizeof(playa.pingu[0]);
    for (int i = 0; i < penguins; i++) {
        if (playa.pingu[i].flag == 1) return 1;
    }
};

int can_any_penguins_be_placed(Player* playa) {
    for (int i = 0; i < player_number; i++){
        for (int j = 0; j < penguins; j++){
            if (playa[i].pingu[j].flag == 1) return 1;
        }
    }

    return 0;
};

int check_if_penguin_can_move(int** board, int x_penguin, int y_penguin) {
    int x = x_penguin + 1;
    int y = y_penguin + 1;

    if (x > 1 && x < columns && y > 1 && y < rows) {
        if (board[y-1][x] > 0 && board[y-1][x] < 4) {
            return 1;
        } else if (board[y][x-1] > 0 && board[y][x-1] < 4) { 
            return 1;
        } else if (board[y-1][x-2] > 0 && board[y-1][x-2] < 4) {
            return 1;
        } else if (board[y-2][x-1] > 0 && board[y-2][x-1] < 4) {
            return 1;
        } else {
            printf("\nThis penguin can't move silly! Please pick a different penguin!\n");
            return 0;
        }
    } else if (x == 1 && y == 1) {
        if (board[y-1][x] > 0 && board[y-1][x] < 4) {
            return 1;
        } else if (board[y][x-1] > 0 && board[y][x-1] < 4) { 
            return 1;
        } else {
            printf("\nThis penguin can't move silly! Please pick a different penguin!\n");
            return 0;
        }
    } else if (x == columns && y == rows) {
        if (board[y-1][x-2] > 0 && board[y-1][x-2] < 4) {
            return 1;
        } else if (board[y-2][x-1] > 0 && board[y-2][x-1] < 4) {
            return 1;
        } else {
            printf("\nThis penguin can't move silly! Please pick a different penguin!\n");
            return 0;
        }
    } else if (x == 1 && y == rows) {
        if (board[y-1][x] > 0 && board[y-1][x] < 4) {
            return 1;
        } else if (board[y-2][x-1] > 0 && board[y-2][x-1] < 4) {
            return 1;
        } else {
            printf("\nThis penguin can't move silly! Please pick a different penguin!\n");
            return 0;
        }
    } else if (x == columns && y == 1) {
        if (board[y-1][x-2] > 0 && board[y-1][x-2] < 4) {
            return 1;
        } else if (board[y][x-1] > 0 && board[y][x-1] < 4) {
            return 1;
        } else {
            printf("\nThis penguin can't move silly! Please pick a different penguin!\n");
            return 0;
        }
    } else if (x == 1 && y > 1 && y < rows) {
        if (board[y-2][x-1] > 0 && board[y-2][x-1] < 4) {
            return 1;
        } else if (board[y][x-1] > 0 && board[y][x-1] < 4) {
            return 1;
        } else if (board[y-1][x] > 0 && board[y-1][x] < 4) {
            return 1;
        } else {
            printf("\nThis penguin can't move silly! Please pick a different penguin!\n");
            return 0;
        }
    } else if (x == columns && y > 1 && y < rows) {
        if (board[y-2][x-1] > 0 && board[y-2][x-1] < 4) {
            return 1;
        } else if (board[y][x-1] > 0 && board[y][x-1] < 4) {
            return 1;
        } else if (board[y-1][x-2] > 0 && board[y-1][x-2] < 4) {
            return 1;
        } else {
            printf("\nThis penguin can't move silly! Please pick a different penguin!\n");
            return 0;
        }
    } else if (x > 1 && x < columns && y == 1) {
        if (board[y-1][x-2] > 0 && board[y-1][x-2] < 4) {
            return 1;
        } else if (board[y][x-1] > 0 && board[y][x-1] < 4) {
            return 1;
        } else if (board[y-1][x] > 0 && board[y-1][x] < 4) {
            return 1;
        } else {
            printf("\nThis penguin can't move silly! Please pick a different penguin!\n");
            return 0;
        }
    } else if (x > 1 && x < columns && y == rows) {
        if (board[y-1][x-2] > 0 && board[y-1][x-2] < 4) {
            return 1;
        } else if (board[y-2][x-1] > 0 && board[y-2][x-1] < 4) {
            return 1;
        } else if (board[y-1][x] > 0 && board[y-1][x] < 4) {
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
            }
            system("clear");
        }
    }
    return 0;
};
