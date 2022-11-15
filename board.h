#include "board.c"

void input_board_dimensions() ;
/*function,which asked players for board dimensions(lenght and width)*/

void generate_board();
/* this function creates a board with given input*/

void display_board();
/*function for displaying the board*/
int check_if_space_on_the_board();
/*used in the placement phase.Checks if there any space on the board
 for penguins,what the players have not yet placed*/

void update_board();
/*it should show all board changes that occur during the game*/
