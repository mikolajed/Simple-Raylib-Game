#include "structures.h"
#include "gameplay_functions.h"
#include <stdlib.h>

#define END_PP 1
#define END_MP 1
#define TRUE 1
#define FALSE 0
#define NONE -1

// this function might be movde to another file
struct board_tile** new_board(int x, int y) {
    struct board_tile** board = (struct board_tile**)malloc(y * sizeof(struct board_tile*));
    int i;
    for (i = 0; i < y; i++)
        board[i] = (struct board_tile*)malloc(x * sizeof(struct board_tile));

    return board;
}
// this function might be moved to another file
void free_board(struct board_tile** board, int x, int y) {
    int i;
    for (i = 0; i < y; i++)
        free(board[i]);

    free(board);
}

int main(int agrc, char **argv) {   
    //init();
    
    //int GUI = 0;
    int n = get_nbr_of_players();
    struct player* players = (struct player*)malloc(n * sizeof(struct player));

    init_players(players, n);
    int x = get_x_dimension();
    int y = get_y_dimension();
    
    //pair dims = get_board_dims();
    //int x = dims.x;
    //int y = dims.y;

    // allocate memory for board and fill with elements using generate_board
    struct board_tile** board = new_board(x, y);
    generate_board(board, x, y);
    show_board(board, x, y);
    
    // in the movement phase we might want to choose ones again the first player to make a move
    int curr_player = choose_first_player(n);
    /*
        PLACEMENT PHASE
    */
    // as long as at least one player can place one of their penguins
    while (placement_game_status(board, players) != END_PP) {
        // check if current player can place a penguin
        if (placement_possible(board, players, curr_player) == TRUE) {
            // until chosen placement is invalid ask for a new one
            int valid;
            struct placement p;
            do {
                show_board(board, x, y);
                p = get_placement();
                valid = valid_placement(board, p);
            } while (valid == FALSE);
            execute_placement(board, players, curr_player, p);
        }
        next_player(&curr_player, n);
    }
   
    /*
        MOVEMENT PHASE
    */
    // as long as at least one player can make a move 
    while (movement_game_status(board, players) != END_MP) {
        // check if currnet player can make a move        
        if (movement_possible(board, players, curr_player) == TRUE) {
            // unitl chosen move is invalid ask for another            
            int valid;
            struct movement m;
            do {
                show_board(board, x, y);
                m = get_movement();
                valid = valid_movement(board, m, curr_player);
            } while (valid == FALSE);
            execute_movement(board, players, curr_player, m);
        }
        next_player(&curr_player, n);
    }
    
    int winner = determine_winner(players, n);
    end_game();

    free_board(board, x, y);
    
    return 0;      
}
