#ifndef MISC
#define MISC
// chooses the first player to start a game
// argumenst: number of players
// returns: random number from range 0..n-1
int choose_first_player(int n);

// changes index of curr_player at given memory adress, for example (curr_player+1)%n
// arguments: address to current player index, number of players in the game
// returns: no value
void next_player(int *curr_player, int n);

// returns: 2D array of dimensions x, y
// IMPORTANT! board[i][j], where i<y and j<x
struct board_tile** new_board(int x, int y);

// frees memory takes by the 2D array
void free_board(struct board_tile** board, int x, int y);
// To-do
void placement_init();
// To-do
void movement_init();

// TO-DO
void init_game();
void end_game();
#endif
