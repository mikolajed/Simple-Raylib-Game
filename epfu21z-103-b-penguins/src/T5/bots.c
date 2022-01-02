#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structures.h"
#include "movement.h"
#include "placement.h"

// Bot level 1
// completly random bot, placement randomly, choosing penguins to move randomly, moving randomly

int bot12_possible_placement(struct board_tile **board, struct player *players, struct bot_placement *placements, int x_size, int y_size)
{
    srand(time(0));
    int place_counter = 0;
    for (int i = 0; i < y_size; i++)
    {
        for (int j = 0; j < x_size; j++)
        {
            if (board[i][j].fishes == 1)
            {
                placements[place_counter].x = j;
                placements[place_counter].y = i;
                place_counter++;
            }
        }
    }
    int placement_decision = (rand() % (place_counter));
    return placement_decision;
}
void bot_placement_execution(struct board_tile **board, struct player *players, struct bot_placement *placements, struct placement p, int curr_player, int placement_decision)
{
    p.to.x = placements[placement_decision].x;
    p.to.y = placements[placement_decision].y;
    board[p.to.y][p.to.x].occupied = players[curr_player - 1].id;
    players[curr_player - 1].fish_collected++; // show player's id on the board
    players[curr_player - 1].pen_not_placed--; // reduce number of penguins of current player after every successful placement
    board[p.to.y][p.to.x].fishes = 0;
}
int bot123_choosing_penguin(struct board_tile **board, struct player *players, struct bot_choosing *choice, int x_size, int y_size, int curr_player)
{
    srand(time(0));
    int choosing_counter = 0;
    for (int i = 0; i < y_size; i++)
    {
        for (int j = 0; j < x_size; j++)
        {
            if (board[i][j].occupied == players[curr_player - 1].id) // CHANGE LINES BELOW
            {
                if (((board[i + 1][j].fishes != 0) && ((board[i + 1][j].occupied == 0))) || ((board[i - 1][j].fishes != 0) && (board[i - 1][j].occupied == 0)) || ((board[i][j + 1].fishes != 0) && (board[i][j + 1].occupied == 0)) || ((board[i][j - 1].fishes != 0) && (board[i][j - 1].occupied == 0)))
                {
                    choice[choosing_counter].x = j;
                    choice[choosing_counter].y = i;
                    choosing_counter++;
                }
            }
        }
    }
    int penguin_decision = (rand() % (choosing_counter));
    return penguin_decision;
}
struct movement bot_choosing_execution(struct board_tile **board, struct player *players, struct bot_choosing *choice, struct movement m, int curr_player, int penguin_decision)
{
    m.from.x = choice[penguin_decision].x;
    m.from.y = choice[penguin_decision].y;
    return m;
}
int bot1_choosing_movement(struct board_tile **board, struct player *players, struct movement m, struct bot_movement *mov_choice, int x_size, int y_size, int curr_player)
{
    srand(time(0));
    int movement_counter = 0;
    int up = 1;
    int down = 1;
    int right = 1;
    int left = 1;

    while ((board[m.from.y + up][m.from.x].fishes != 0) && (board[m.from.y + up][m.from.x].occupied == 0))
    {
        mov_choice[movement_counter].x = (m.from.x);
        mov_choice[movement_counter].y = (m.from.y + up);
        up++;
        movement_counter++;
    }
    while ((board[m.from.y - down][m.from.x].fishes != 0) && (board[m.from.y - down][m.from.x].occupied == 0))
    {
        mov_choice[movement_counter].x = (m.from.x);
        mov_choice[movement_counter].y = (m.from.y - down);
        down++;
        movement_counter++;
    }
    while ((board[m.from.y][m.from.x + right].fishes != 0) && (board[m.from.y][m.from.x + right].occupied == 0))
    {
        mov_choice[movement_counter].x = (m.from.x + right);
        mov_choice[movement_counter].y = (m.from.y);
        right++;
        movement_counter++;
    }
    while ((board[m.from.y][m.from.x - left].fishes != 0) && (board[m.from.y][m.from.x - left].occupied == 0))
    {
        mov_choice[movement_counter].x = (m.from.x - left);
        mov_choice[movement_counter].y = (m.from.y);
        left++;
        movement_counter++;
    }
    int movement_decision = (rand() % (movement_counter));
    return movement_decision;
}

// bot level 2
// Random placement, random choosing penguins, moving on tiles with 3 in prioritet, then on 2, then 1

int bot2_choosing_movement(struct board_tile **board, struct player *players, struct movement m, struct bot_movement *mov_choice, int x_size, int y_size, int curr_player)
{
    srand(time(0));
    int movement_counter = 0;
    int up = 1;
    int down = 1;
    int right = 1;
    int left = 1;

    while ((board[m.from.y + up][m.from.x].fishes != 0) && (board[m.from.y + up][m.from.x].occupied == 0))
    {
        mov_choice[movement_counter].x = (m.from.x);
        mov_choice[movement_counter].y = (m.from.y + up);
        up++;
        movement_counter++;
    }
    while ((board[m.from.y - down][m.from.x].fishes != 0) && (board[m.from.y - down][m.from.x].occupied == 0))
    {
        mov_choice[movement_counter].x = (m.from.x);
        mov_choice[movement_counter].y = (m.from.y - down);
        down++;
        movement_counter++;
    }
    while ((board[m.from.y][m.from.x + right].fishes != 0) && (board[m.from.y][m.from.x + right].occupied == 0))
    {
        mov_choice[movement_counter].x = (m.from.x + right);
        mov_choice[movement_counter].y = (m.from.y);
        right++;
        movement_counter++;
    }
    while ((board[m.from.y][m.from.x - left].fishes != 0) && (board[m.from.y][m.from.x - left].occupied == 0))
    {
        mov_choice[movement_counter].x = (m.from.x - left);
        mov_choice[movement_counter].y = (m.from.y);
        left++;
        movement_counter++;
    }
    int prior_tiles[movement_counter];
    int prior_counter = 0;
    for (int i = 0; i < movement_counter; i++)
    {
        if (board[mov_choice[i].y][mov_choice[i].x].fishes == 3)
        {
            prior_tiles[prior_counter] = i;
            prior_counter++;
        }
    }
    if (prior_counter != 0)
    {
        int preliminary_decision = (rand() % (prior_counter));
        int movement_decision = prior_tiles[preliminary_decision];
        return movement_decision;
    }
    prior_counter = 0;
    for (int i = 0; i < movement_counter; i++)
    {
        if (board[mov_choice[i].y][mov_choice[i].x].fishes == 2)
        {
            prior_tiles[prior_counter] = i;
            prior_counter++;
        }
    }
    if (prior_counter != 0)
    {
        int preliminary_decision = (rand() % (prior_counter));
        int movement_decision = prior_tiles[preliminary_decision];
        return movement_decision;
    }
    int movement_decision = (rand() % (movement_counter));
    return movement_decision;
}

// bot level 3
// Random placement, random choosing penguins, moving on tiles with 3 in prioritet, then on 2, then 1,
// escapes simple traps,places penguins accrording to the amount of tiles with 3 it would be able to reach
int bot34_possible_placement(struct board_tile **board, struct player *players, struct bot_placement *placements, int x_size, int y_size)
{
    srand(time(0));
    int place_counter = 0;
    // int position_counter = 0;
    int temp = 0;

    for (int i = 0; i < y_size; i++)
    {
        for (int j = 0; j < x_size; j++)
        {
            if (board[i][j].fishes == 1)
            {
                placements[place_counter].x = j;
                placements[place_counter].y = i;
                place_counter++;
            }
        }
    }
    // int good_placement[place_counter];
    int potential_counter[place_counter];
    for (int i = 0; i < place_counter; i++)
    {
        potential_counter[i] = 0;
    }
    for (int i = 0; i < place_counter; i++)
    {
        int up = 1;
        int down = 1;
        int right = 1;
        int left = 1;
        while ((board[placements[i].y + up][placements[i].x].fishes != 0) && (board[placements[i].y + up][placements[i].x].occupied == 0))
        {
            if (board[placements[i].y + up][placements[i].x].fishes == 3)
            {
                potential_counter[i]++;
            }
            up++;
        }
        while (board[placements[i].y - down][placements[i].x].fishes != 0 && (board[placements[i].y - down][placements[i].x].occupied == 0))
        {
            if (board[placements[i].y - down][placements[i].x].fishes == 3)
            {
                potential_counter[i]++;
            }
            down++;
        }
        while (board[placements[i].y][placements[i].x + right].fishes != 0 && board[placements[i].y][placements[i].x + right].occupied == 0)
        {
            if (board[placements[i].y][placements[i].x + right].fishes == 3)
            {
                potential_counter[i]++;
            }
            right++;
        }

        while (board[placements[i].y][placements[i].x - left].fishes != 0 && board[placements[i].y][placements[i].x - left].occupied == 0)
        {
            if (board[placements[i].y][placements[i].x - left].fishes == 3)
            {
                potential_counter[i]++;
            }
            left++;
        }
    }
    for (int i = 0; i < place_counter; i++)
    {
        if (potential_counter[i] > temp)
        {
            temp = potential_counter[i];
        }
    }
    for (int i = 0; i < place_counter; i++)
    {
        if (potential_counter[i] == temp)
        {
            temp = i;
            break;
        }
    }
    if (temp != 0)
    {
        int placement_decision = temp;
        return placement_decision;
    }
    else
    {
        for (int i = 0; i < place_counter; i++)
        {
            potential_counter[i] = 0;
        }
        for (int i = 0; i < place_counter; i++)
        {
            int up = 1;
            int down = 1;
            int right = 1;
            int left = 1;
            while (board[placements[i].y + up][placements[i].x].fishes != 0 && board[placements[i].y + up][placements[i].x].occupied == 0)
            {
                if (board[placements[i].y + up][placements[i].x].fishes == 2)
                {
                    potential_counter[i]++;
                }
                up++;
            }
            while (board[placements[i].y - down][placements[i].x].fishes != 0 && (board[placements[i].y - down][placements[i].x].occupied == 0))
            {
                if (board[placements[i].y - down][placements[i].x].fishes == 2)
                {
                    potential_counter[i]++;
                }
                down++;
            }
            while (board[placements[i].y][placements[i].x + right].fishes != 0 && board[placements[i].y][placements[i].x + right].occupied == 0)
            {
                if (board[placements[i].y][placements[i].x + right].fishes == 2)
                {
                    potential_counter[i]++;
                }
                right++;
            }
            while (board[placements[i].y][placements[i].x - left].fishes != 0 && board[placements[i].y][placements[i].x - left].occupied == 0)
            {
                if (board[placements[i].y][placements[i].x - left].fishes == 2)
                {
                    potential_counter[i]++;
                }
                left++;
            }
        }
        for (int i = 0; i < place_counter; i++)
        {
            if (potential_counter[i] > temp)
            {
                temp = potential_counter[i];
            }
        }
        for (int i = 0; i < place_counter; i++)
        {
            if (potential_counter[i] == temp)
            {
                temp = i;
                break;
            }
        }
        if (temp != 0)
        {
            int placement_decision = temp;
            return placement_decision;
        }
    }
    int placement_decision = (rand() % (place_counter));
    return placement_decision;
}
int bot3_choosing_movement(struct board_tile **board, struct player *players, struct movement m, struct bot_movement *mov_choice, int x_size, int y_size, int curr_player)
{
    srand(time(0));
    int movement_counter = 0;
    int up = 1;
    int down = 1;
    int right = 1;
    int left = 1;
    int temp = 0;
    int preliminary_decision = 0;

    while ((board[m.from.y + up][m.from.x].fishes != 0) && (board[m.from.y + up][m.from.x].occupied == 0))
    {
        mov_choice[movement_counter].x = (m.from.x);
        mov_choice[movement_counter].y = (m.from.y + up);
        up++;
        movement_counter++;
    }
    while ((board[m.from.y - down][m.from.x].fishes != 0) && (board[m.from.y - down][m.from.x].occupied == 0))
    {
        mov_choice[movement_counter].x = (m.from.x);
        mov_choice[movement_counter].y = (m.from.y - down);
        down++;
        movement_counter++;
    }
    while ((board[m.from.y][m.from.x + right].fishes != 0) && (board[m.from.y][m.from.x + right].occupied == 0))
    {
        mov_choice[movement_counter].x = (m.from.x + right);
        mov_choice[movement_counter].y = (m.from.y);
        right++;
        movement_counter++;
    }
    while ((board[m.from.y][m.from.x - left].fishes != 0) && (board[m.from.y][m.from.x - left].occupied == 0))
    {
        mov_choice[movement_counter].x = (m.from.x - left);
        mov_choice[movement_counter].y = (m.from.y);
        left++;
        movement_counter++;
    }
    int prior_tiles[movement_counter];
    int prior_counter = 0;
    int amount_of_directions[movement_counter];
    for (int i = 0; i < movement_counter; i++)
    {
        amount_of_directions[i] = 0;
    }
    for (int i = 0; i < movement_counter; i++)
    {
        if (board[mov_choice[i].y][mov_choice[i].x].fishes != 0)
        {
            if (board[mov_choice[i].y + 1][mov_choice[i].x].fishes != 0)
            {
                amount_of_directions[i]++;
            }
            if (board[mov_choice[i].y - 1][mov_choice[i].x].fishes != 0)
            {
                amount_of_directions[i]++;
            }
            if (board[mov_choice[i].y][mov_choice[i].x + 1].fishes != 0)
            {
                amount_of_directions[i]++;
            }
            if (board[mov_choice[i].y][mov_choice[i].x - 1].fishes != 0)
            {
                amount_of_directions[i]++;
            }
        }
    }
    for (int i = 0; i < movement_counter; i++)
    {
        if (amount_of_directions[i] > temp && board[mov_choice[i].y][mov_choice[i].x].fishes == 3)
        {
            temp = amount_of_directions[i];
        }
    }
    for (int i = 0; i < movement_counter; i++)
    {
        if (amount_of_directions[i] == temp && board[mov_choice[i].y][mov_choice[i].x].fishes == 3)
        {
            temp = i;
        }
    }
    if (temp != 0)
    {
        int movement_decision = temp;
        return movement_decision;
    }
    for (int i = 0; i < movement_counter; i++)
    {
        if (amount_of_directions[i] > temp && board[mov_choice[i].y][mov_choice[i].x].fishes == 2)
        {
            temp = amount_of_directions[i];
        }
    }
    for (int i = 0; i < movement_counter; i++)
    {
        if (amount_of_directions[i] == temp && board[mov_choice[i].y][mov_choice[i].x].fishes == 2)
        {
            temp = i;
        }
    }
    if (temp != 0)
    {
        int movement_decision = temp;
        return movement_decision;
    }
    for (int i = 0; i < movement_counter; i++)
    {
        if (amount_of_directions[i] > temp && board[mov_choice[i].y][mov_choice[i].x].fishes == 1)
        {
            temp = amount_of_directions[i];
        }
    }
    for (int i = 0; i < movement_counter; i++)
    {
        if (amount_of_directions[i] == temp && board[mov_choice[i].y][mov_choice[i].x].fishes == 1)
        {
            temp = i;
        }
    }
    int movement_decision = temp;
    return movement_decision;
}

/*



 * BOT GENERAL FUNCTIONS



 */
void execute_placement_bot(struct board_tile **board, int x, int y, struct player *players, int n, int curr_player)
{
    struct placement p;
    struct bot_placement *placements = (struct bot_placement *)malloc(x * y * sizeof(struct bot_placement));
    switch (players[curr_player - 1].bot_level)
    {
    case 1:
    {
        int placement_decision = bot12_possible_placement(board, players, placements, x, y);
        bot_placement_execution(board, players, placements, p, curr_player, placement_decision);
        break;
    }
    case 2:
    {
        int placement_decision = bot12_possible_placement(board, players, placements, x, y); // has the same way of choosing placement as 1st
        bot_placement_execution(board, players, placements, p, curr_player, placement_decision);
        break;
    }
    case 3:
    {
        int placement_decision = bot34_possible_placement(board, players, placements, x, y); // has the same way of choosing placement as 1st
        bot_placement_execution(board, players, placements, p, curr_player, placement_decision);
        break;
    }

        // free the memory
        free(placements);
    }
}
struct movement bot_mov_choosing_execution(struct board_tile **board, struct player *players, struct bot_movement *mov_choice, struct movement m, int curr_player, int movement_decision)
{
    m.to.x = mov_choice[movement_decision].x;
    m.to.y = mov_choice[movement_decision].y;
    return m;
}

void execute_movement_bot(struct board_tile **board, int x, int y, struct player *players, int n, int curr_player)
{
    struct movement m;
    struct bot_choosing *choice = (struct bot_choosing *)malloc(x * y * sizeof(struct bot_choosing));
    struct bot_movement *mov_choice = (struct bot_movement *)malloc(x * y * sizeof(struct bot_movement));

    switch (players[curr_player - 1].bot_level)
    {
    case 1:
    {
        int penguin_decision = bot123_choosing_penguin(board, players, choice, x, y, curr_player);
        m = bot_choosing_execution(board, players, choice, m, curr_player, penguin_decision);
        int movement_deicision = bot1_choosing_movement(board, players, m, mov_choice, x, y, curr_player);
        m = bot_mov_choosing_execution(board, players, mov_choice, m, curr_player, movement_deicision);
        execute_movement(board, players, curr_player, m);
        break;
    }
    case 2:
    {
        int penguin_decision = bot123_choosing_penguin(board, players, choice, x, y, curr_player); // same choosing
        m = bot_choosing_execution(board, players, choice, m, curr_player, penguin_decision);
        int movement_deicision = bot2_choosing_movement(board, players, m, mov_choice, x, y, curr_player);
        m = bot_mov_choosing_execution(board, players, mov_choice, m, curr_player, movement_deicision);
        execute_movement(board, players, curr_player, m);
        break;
    }
    case 3:
    {
        int penguin_decision = bot123_choosing_penguin(board, players, choice, x, y, curr_player); // same choosing
        m = bot_choosing_execution(board, players, choice, m, curr_player, penguin_decision);
        int movement_deicision = bot3_choosing_movement(board, players, m, mov_choice, x, y, curr_player);
        m = bot_mov_choosing_execution(board, players, mov_choice, m, curr_player, movement_deicision);
        execute_movement(board, players, curr_player, m);
        break;
    }
        // free the memory
        free(choice);
        free(mov_choice);
    }
    // for tests: || 3 a 1 3 b 1 2 c 1 1 3 15 15 || 3 a 1 3 b 1 2 c 1 1 1 10 10
}
