#ifndef BOTS
#define BOTS
// find which tiles the bot can place its penguins on
int bot_possible_placement(struct board_tile **board, struct player *players, struct bot_placement *placements, int x_size, int y_size);
// place bot's penguins
void bot1_placement_execution(struct board_tile **board, struct player *players, struct bot_placement *placements, struct placement p, int curr_player, int place_counter);
// find all penguins the bot can move and store them in an array
int bot1_choosing_penguin(struct board_tile **board, struct player *players, struct bot_choosing *choice, int x_size, int y_size, int curr_player);
// choose penguin which the bot will operate next and store penguins cords
struct movement bot1_choosing_execution(struct board_tile **board, struct player *players, struct bot_choosing *choice, struct movement m, int curr_player, int penguin_decision);
// find all the tiles the penguin could move onto
int bot1_choosing_movement(struct board_tile **board, struct player *players, struct movement m, struct bot_movement *mov_choice,  int x_size, int y_size, int curr_player);
// apply the tile the bot choose to go onto
struct movement bot_mov_choosing_execution(struct board_tile **board, struct player *players, struct bot_movement *mov_choice, struct movement m, int curr_player, int movement_decision);
#endif
