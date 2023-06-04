/**
*
* @author SEIDY KANTE
* <p>
*		Main
* </p>
*/

#include "Game.h"

int main(){

    Game this_game =new_Game();
    this_game->run(this_game);
    this_game->delete_Game(this_game);

    return 0;
}