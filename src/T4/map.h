#ifndef MAPFUNCTIONS
#define MAPFUNCTIONS
// displays the board to command line
void show_board(struct board_tile** board, int x, int y);
// each tile for the board is filled with new values
// arguments: board, board's x and y dimension
// returns: no value
void generate_board(struct board_tile** board, int x, int y);
// checks if there are enough tiles with 1 fish on it for the game to be playable 
void board_gen_check(struct board_tile **board,struct player* players, int x_size, int y_size,int n);
#endif
