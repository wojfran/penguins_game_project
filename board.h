extern int columns, rows;

int** allocate_memory_for_board(int columns, int rows);
/* this function allocates memory for a board based on the input x an y parameters*/

void generate_board(int** board);
/* this function creates a board with given input*/

void display_board();
/*function for displaying the board*/

void free_board_memory(int** board, int x);

int check_if_space_on_the_board();
/*used in the placement phase.Checks if there any space on the board
 for penguins,what the players have not yet placed*/

void update_board();
/*it should show all board changes that occur during the game*/
