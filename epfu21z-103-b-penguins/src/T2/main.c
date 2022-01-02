#include "structures.h"
#include "gameplay_functions.h"
#include <stdlib.h>

#define END_PP -1
#define END_MP -1
#define TRUE 1
#define FALSE 0
#define NONE -1

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
    //int board[x][y] = generate_board(x, y);
    // in the movement phase we might want to choose ones again the first player to make a move
    //int curr_player = choose_first_player();
    /*
        PLACEMENT PHASE
    */
    // as long as at least one player can place one of their penguins
    /*while (placement_game_status() != END_PP) {
        // check if current player can place a penguin
        if (placement_possible() == TRUE) {
            // until chosen placement is invalid ask for a new one
            do {
                placement p = get_placement();
                int valid = valid_placement(p);
            } while (valid == FALSE);
            execute_placement(p);
        next_player();
    }
    */
    /*
        MOVEMENT PHASE
    */
    // as long as at least one player can make a move 
    /*while (movement_game_status() != END_MP) {
        // check if currnet player can make a move        
        if (movement_possible() == TRUE) {
            // unitl chosen move is invalid ask for another            
            do {
                movement m = get_movement();
                int valid = valid_movement(m);
            } while (valid == FALSE);
            execute_movement(m);
        next_player();
    }
    
    player winner = determine_winner();
    end_game();
    */      
}
