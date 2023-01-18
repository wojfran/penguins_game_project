#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "movement.h"
#include "player.h"
#include "penguins.h"
extern int player_number, penguins, x, y, x_penguin, y_penguin, rows, columns;

int check_if_current_players_penguins_can_be_placed(Player playa) {
    for (int i = 0; i < penguins; i++) {
        if (playa.pingu[i].x == -1) return 1;  
    }
    return 0;
};

int check_if_penguin_can_move(int** board, int x_penguin, int y_penguin) {
    int x = x_penguin + 1;
    int y = y_penguin + 1;


    if (x > 1 && x < columns && y > 1 && y < rows) {
        if (board[y-1][x] > 0 && (board[y-1][x] % 10) == 0) {
            return 1;
        } else if (board[y][x-1] > 0 && (board[y][x-1]% 10) == 0) { 
            return 1;
        } else if (board[y-1][x-2] > 0 && (board[y-1][x-2] % 10) == 0) {
            return 1;
        } else if (board[y-2][x-1] > 0 && (board[y-2][x-1] % 10) == 0) {
            return 1;
        } else {
            printf("\nPenguin with the coordinates x: %d and y: %d cannot move.\n", x_penguin, y_penguin);
            return 0;
        }
    } else if (x == 1 && y == 1) {
        if (board[y-1][x] > 0 && (board[y-1][x] % 10) == 0) {;
            return 1;
        } else if (board[y][x-1] > 0 && (board[y][x-1] % 10) == 0) { 
            return 1;
        } else {
            printf("\nPenguin with the coordinates x: %d and y: %d cannot move.\n", x_penguin, y_penguin);
            return 0;
        }
    } else if (x == columns && y == rows) {
        if (board[y-1][x-2] > 0 && (board[y-1][x-2] % 10) == 0) {
            return 1;
        } else if (board[y-2][x-1] > 0 && (board[y-2][x-1] % 10) == 0) {
            return 1;
        } else {
            printf("\nPenguin with the coordinates x: %d and y: %d cannot move.\n", x_penguin, y_penguin);
            return 0;
        }
    } else if (x == 1 && y == rows) {
        if (board[y-1][x] > 0 && (board[y-1][x] % 10) == 0) {
            return 1;
        } else if (board[y-2][x-1] > 0 && (board[y-2][x-1] % 10) == 0) {
            return 1;
        } else {
            printf("\nPenguin with the coordinates x: %d and y: %d cannot move.\n", x_penguin, y_penguin);
            return 0;
        }
    } else if (x == columns && y == 1) {
        if (board[y-1][x-2] > 0 && (board[y-1][x-2] % 10) == 0) {
            return 1;
        } else if (board[y][x-1] > 0 && (board[y][x-1] % 10) == 0) {
            return 1;
        } else {
            printf("\nPenguin with the coordinates x: %d and y: %d cannot move.\n", x_penguin, y_penguin);
            return 0;
        }
    } else if (x == 1 && y > 1 && y < rows) {
        if (board[y-2][x-1] > 0 && (board[y-2][x-1] % 10) == 0) {
            return 1;
        } else if (board[y][x-1] > 0 && (board[y][x-1] % 10) == 0) {
            return 1;
        } else if (board[y-1][x] > 0 && (board[y-1][x] % 10) == 0) {
            return 1;
        } else {
            printf("\nPenguin with the coordinates x: %d and y: %d cannot move.\n", x_penguin, y_penguin);
            return 0;
        }
    } else if (x == columns && y > 1 && y < rows) {
        if (board[y-2][x-1] > 0 && (board[y-2][x-1] % 10) == 0) {
            return 1;
        } else if (board[y][x-1] > 0 && (board[y][x-1] % 10) == 0) {
            return 1;
        } else if (board[y-1][x-2] > 0 && (board[y-1][x-2] % 10) == 0) {
            return 1;
        } else {
            printf("\nPenguin with the coordinates x: %d and y: %d cannot move.\n", x_penguin, y_penguin);
            return 0;
        }
    } else if (x > 1 && x < columns && y == 1) {
        if (board[y-1][x-2] > 0 && (board[y-1][x-2] % 10) == 0) {
            return 1;
        } else if (board[y][x-1] > 0 && (board[y][x-1] % 10) == 0) {
            return 1;
        } else if (board[y-1][x] > 0 && (board[y-1][x] % 10) == 0) {
            return 1;
        } else {
            printf("\nPenguin with the coordinates x: %d and y: %d cannot move.\n", x_penguin, y_penguin);
            return 0;
        }
    } else if (x > 1 && x < columns && y == rows) {
        if (board[y-1][x-2] > 0 && (board[y-1][x-2] % 10) == 0) {
            return 1;
        } else if (board[y-2][x-1] > 0 && (board[y-2][x-1] % 10) == 0) {
            return 1;
        } else if (board[y-1][x] > 0 && (board[y-1][x] % 10) == 0) {
            return 1;
        } else {
            printf("\nPenguin with the coordinates x: %d and y: %d cannot move.\n", x_penguin, y_penguin);
            return 0;
        }
    } else {
        printf("\nUnknown Situation\n");
        return 1;
    }
}; 

int check_if_current_players_penguins_can_move(Player playa, int** board) {

    int check = 0;

    for (int i = 0; i < penguins; i++) {
        int x = playa.pingu[i].x;
        int y = playa.pingu[i].y;
        if(!check_if_penguin_can_move(board, x, y)) check++;
    }

    if (check == penguins) return 0;
    else return 1;
}

int determine_quadrant_with_least_penguins(Player playa, int** board) {
    int quadrants[4] = {0, 0, 0, 0};

    for (int i = 0; i < penguins; i++) {
        if(playa.pingu[i].x != -1){
            if(playa.pingu[i].x+1 <= columns/2  && playa.pingu[i].y+1 <= rows/2) quadrants[0]++;
            if(playa.pingu[i].x+1 > columns/2 && playa.pingu[i].y+1 <= rows/2) quadrants[1]++;
            if(playa.pingu[i].x+1 <= columns/2  && playa.pingu[i].y+1 > rows/2) quadrants[2]++;
            if(playa.pingu[i].x+1 > columns/2 && playa.pingu[i].y+1 > rows/2) quadrants[3]++;
        }
    }

    determine_which_quadrants_are_full(board, quadrants);

    int min = quadrants[0];
    int quadrant = 0;

    for (int i = 0; i < 4; i++) {
        printf("Quadrant: %d Amount of penguins: %d\n", i, quadrants[i]);
        if (quadrants[i] < min) {
            min = quadrants[i];
            quadrant = i;
        }
    }

    return quadrant;
}

void determine_which_quadrants_are_full(int** board, int quadrants[4]) {
    int minrow, maxrow, mincol, maxcol, check;

    for (int q = 0; q < 4; q++){
        check = 0;
        if (q == 0) {
            minrow = 0;
            mincol= 0;
            maxrow = rows/2;
            maxcol = columns/2;
        } else if (q == 1) {
            minrow = 0;
            mincol= columns/2;
            maxrow = rows/2;
            maxcol = columns;
        } else if (q == 2) {
            minrow = rows/2;
            mincol= 0;
            maxrow = rows;
            maxcol = columns/2;
        } else if (q == 3) {
            minrow = rows/2;
            mincol= columns/2;
            maxrow = rows;
            maxcol = columns;
        }

        printf("Quadrant %d\n", q);
        for(int i = minrow; i < maxrow; i++){
            for (int j = mincol; j < maxcol; j++){
                printf("%d  ", board[i][j]);
                if (board[i][j] == 10) {
                    check = 1;
                }
            }
            printf("\n");
        }
        if (check != 1) quadrants[q] = 999;
    }
}

void automatic_placement_quadrant_method(Player playa, int** board){

    int quadrant_with_least_penguins = determine_quadrant_with_least_penguins(playa, board);
    printf("Quadrant with least penguins: %d\n", quadrant_with_least_penguins);
    int minrow, maxrow, mincol, maxcol;

    if (quadrant_with_least_penguins == 0) {
        minrow = 0;
        mincol= 0;
        maxrow = rows/2;
        maxcol = columns/2;
    } else if (quadrant_with_least_penguins == 1) {
        minrow = 0;
        mincol= columns/2;
        maxrow = rows/2;
        maxcol = columns;
    } else if (quadrant_with_least_penguins == 2) {
        minrow = rows/2;
        mincol= 0;
        maxrow = rows;
        maxcol = columns/2;
    } else if (quadrant_with_least_penguins == 3) {
        minrow = rows/2;
        mincol= columns/2;
        maxrow = rows;
        maxcol = columns;
    } 

    for(int i = minrow; i < maxrow; i++){
        for (int j = mincol; j < maxcol; j++){
            if (board[i][j] == 10) {
                
                x = j+1;
                printf("X: %d", x);
                y = i+1;
                printf("Y: %d", y);

                return;
            }
        }
    }
}

void automatic_placement_chess_method(Player playa, int** board) {
    x = columns/2;
    y = rows/2;
    int dir=1;
    int n = 1;
    int check = 0;

    while (board[y-1][x-1] != 10 || n < 3) {
        if (dir == 1) {
            for (int i = 0; i < n; i++) {
                x++;
                if (board[y-1][x-1] == 10) {
                    if (check == 1) return;
                }
            }
            dir = 2;
            continue;
        } else if (dir == 2) {
            for (int i = 0; i < n; i++) {
                y++;
                if (board[y-1][x-1] == 10) {
                    if (check == 1) return;
                }
            }
            dir = 3;
            n++;
            continue;
        } else if (dir == 3) {
            for (int i = 0; i < n; i++) {
                x--;
                if (board[y-1][x-1] == 10) {
                    if (check == 1) return;
                }
            }
            dir = 4;
            continue;
        } else if (dir == 4) {
            for (int i = 0; i < n; i++) {
                y--;
                if (board[y-1][x-1] == 10) {
                    if (check == 1) return;
                }
            }
            dir = 1;
            n++;
            continue;
        }
        if (n > 2) check = 1;
    }

    printf("X: %d\nY: %d\n", x, y);
    printf("Value: %d", board[y-1][x-1]);
}

void place_penguin(Player* playa, int** board){
    for(int i = 0; i < penguins; i++){
        if (playa->pingu[i].x == -1){
            playa->score +=board[y-1][x-1]/10;
            board[y-1][x-1] = playa->index;
            playa->pingu[i].x = x-1;
            playa->pingu[i].y = y-1;
            break;
        }
    }
}

int determine_best_direction_to_move_penguin_fishwise(int** board, int x_penguin, int y_penguin) {
    int xp = x_penguin + 1;
    int yp = y_penguin + 1;
    int best_move;
    int max_fish;

    // different array indexes signify directions:
    // 0 - right
    // 1 - down
    // 2 - left
    // 3 - up
    // the value they store is the information about the amount
    // of fish on the chosen ice floe
    int floes[4] = {0, 0, 0, 0};

    if (xp > 1 && xp < columns && yp > 1 && yp < rows) {

        if (board[yp-1][xp] > 0 && (board[yp-1][xp] % 10) == 0) floes[0] = board[yp-1][xp] / 10;

        if (board[yp][xp-1] > 0 && (board[yp][xp-1]% 10) == 0) floes[1] = board[yp][xp-1] / 10;

        if (board[yp-1][xp-2] > 0 && (board[yp-1][xp-2] % 10) == 0) floes[2] = board[yp-1][xp-2] / 10;
            
        if (board[yp-2][xp-1] > 0 && (board[yp-2][xp-1] % 10) == 0) floes[3] = board[yp-2][xp-1] / 10;

    } else if (xp == 1 && yp == 1) {

        if (board[yp-1][xp] > 0 && (board[yp-1][xp] % 10) == 0) floes[0] = board[yp-1][xp] / 10;

        if (board[yp][xp-1] > 0 && (board[yp][xp-1] % 10) == 0) floes[1] = board[yp][xp-1] / 10;

    } else if (xp == columns && yp == rows) {

        if (board[yp-1][xp-2] > 0 && (board[yp-1][xp-2] % 10) == 0) floes[2] = board[yp-1][xp-2] / 10;

        if (board[yp-2][xp-1] > 0 && (board[yp-2][xp-1] % 10) == 0) floes[3] = board[yp-2][xp-1] / 10;

    } else if (xp == 1 && yp == rows) {

        if (board[yp-1][xp] > 0 && (board[yp-1][xp] % 10) == 0) floes[0] = board[yp-1][xp] / 10;

        if (board[yp-2][xp-1] > 0 && (board[yp-2][xp-1] % 10) == 0) floes[3] = board[yp-2][xp-1] / 10;

    } else if (xp == columns && yp == 1) {

        if (board[yp-1][xp-2] > 0 && (board[yp-1][xp-2] % 10) == 0) floes[2] = board[yp-1][xp-2] / 10;

        if (board[yp][xp-1] > 0 && (board[yp][xp-1] % 10) == 0) floes[1] = board[yp][xp-1] / 10;

    } else if (xp == 1 && yp > 1 && yp < rows) {

        if (board[yp-2][xp-1] > 0 && (board[yp-2][xp-1] % 10) == 0) floes[3] = board[yp-2][xp-1] / 10;

        if (board[yp][xp-1] > 0 && (board[yp][xp-1] % 10) == 0) floes[1] = board[yp][xp-1] / 10;

        if (board[yp-1][xp] > 0 && (board[yp-1][xp] % 10) == 0) floes[0] = board[yp-1][xp] / 10;

    } else if (xp == columns && yp > 1 && yp < rows) {

        if (board[yp-2][xp-1] > 0 && (board[yp-2][xp-1] % 10) == 0) floes[3] = board[yp-2][xp-1] / 10;

        if (board[yp][xp-1] > 0 && (board[yp][xp-1] % 10) == 0) floes[1] = board[yp][xp-1] / 10;

        if (board[yp-1][xp-2] > 0 && (board[yp-1][xp-2] % 10) == 0) floes[2] = board[yp-1][xp-2] / 10;

    } else if (xp > 1 && xp < columns && yp == 1) {

        if (board[yp-1][xp-2] > 0 && (board[yp-1][xp-2] % 10) == 0) floes[2] = board[yp-1][xp-2] / 10;

        if (board[yp][xp-1] > 0 && (board[yp][xp-1] % 10) == 0) floes[1] = board[yp][xp-1] / 10;

        if (board[yp-1][xp] > 0 && (board[yp-1][xp] % 10) == 0) floes[0] = board[yp-1][xp] / 10;

    } else if (xp > 1 && xp < columns && yp == rows) {

        if (board[yp-1][xp-2] > 0 && (board[yp-1][xp-2] % 10) == 0) floes[2] = board[yp-1][xp-2] / 10;

        if (board[yp-2][xp-1] > 0 && (board[yp-2][xp-1] % 10) == 0) floes[3] = board[yp-2][xp-1] / 10;

        if (board[yp-1][xp] > 0 && (board[yp-1][xp] % 10) == 0) floes[0] = board[yp-1][xp] / 10;

    } else {
        printf("\nUnknown Situation\n");
        return 1;
    }

    best_move = 0;
    max_fish = floes[0];

    for (int i = 1; i < 4; i++) {
        if (floes[i] > max_fish) {
            max_fish = floes[i];
            best_move = i;
        }
    }
    
    return best_move;
}

void automatically_pick_movement_coordinates(Player playa, int** board){
    int direction;
    int counter = 0;
    srand(time(NULL));
    int penguin_num = (rand() % penguins);
    do {
        int xp = playa.pingu[penguin_num].x;
        int yp = playa.pingu[penguin_num].y;
        x_penguin = xp;
        y_penguin = yp;
        if (check_if_penguin_can_move(board, xp, yp)){
            direction = determine_best_direction_to_move_penguin_fishwise(board, xp, yp);
            if (direction == 0) {
                x = xp+2;
                y = yp+1;
            } else if (direction == 1) {
                x = xp+1;
                y = yp+2;
            } else if (direction == 2) {
                x = xp;
                y = yp+1;
            } else if (direction == 3) {
                x = xp+1;
                y = yp;
            }
            return;
        } else {
            counter++;
            penguin_num++;
            if(penguin_num == penguins) penguin_num = 0;
        }
    } while(counter < penguins);
    return;
}

void move_penguin(int** board, Player* playa, int x_penguin, int y_penguin, int x, int y){

    printf("x_penguin: %d\ny_penguin: %d\nx: %d\ny: %d\n", x_penguin+1, y_penguin+1, x, y);
    int penguin_index = (board[y_penguin][x_penguin]);
    playa->pingu[penguin_index-1].x=x-1;
    playa->pingu[penguin_index-1].y=y-1;
    playa->score += board[y-1][x-1]/10;
    board[y-1][x-1] = playa->index;
    board[y_penguin][x_penguin] = 0;
}

