#ifndef AUTOFUN
#define AUTOFUN
// fucntion is run by main if game is played in autonomous mode, executes command given in command line arguments
// arguemtns: game state, number of command line arguments, command line arguemtns
// returns: no value
void execute_autonomous_command(struct GameState* state, int argc, char **argv);
// this funcitons is only run in autonoous mode, checks if command line arguments are valid - according to documenation
// arguments: number of command line arguments, command line arguments
// returns: 1 if cla are invalid, 0 otherwise 
int invalid_cla(int agrc, char **argv);
#endif
