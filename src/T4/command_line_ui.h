//
// Created by timur on 12/5/21.
//

// asks user for the number of players
// arguments: none
// returns: number of players
int get_nbr_of_players();

// asks user for number of penguins each player will have at their disposal
// arguments: none
// returns: number of penguins
int get_nbr_of_penguins();

// sets initial parameters for each player
// arguments: pointer to array's first index and number n of players to be initialized - score, penguins left etc.
// returns: no value
void init_players(struct player* array, int n);

// asks user for x dimension of the map
// arguments: none
// returns: the size of the map's x dimension
int get_x_dimension();

// asks user for y dimension of the map
// arguments: none
// returns: the size of the map's y dimension
int get_y_dimension();

// asks user for coordinates of placement of one of their penguins
// arguments: number of columns and rows
// returns: placement type
struct placement get_placement(int number_of_columns, int number_of_rows);

// asks user for coordinates of the tile the penguins is being moved from and coordinates of the tile the penguins is moved to
// arguments: number of columns and rows
// returns: movement type
struct movement get_movement(int number_of_columns, int number_of_rows);

// displays on the screen the name of current players with a message, is used to determine which player turn it is
// arguments: players, id of current player
// returns: no value
void display_curr_player(struct player* players, int curr_player);

// displays error messange to the screen
void print_invalid_placement();

// displays_error message to the screen
void print_invalid_movement();

// printf winnwer and message that sums up the game
// arugments: array of players and its size n, winner_id is in range [1,n]
// returns: no value
void print_winner(struct player* players, int n, int winner_id);
// askes the user if a player would be under bot's control
int check_if_ai();
