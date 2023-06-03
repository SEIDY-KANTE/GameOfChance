/**
*
* @author SEIDY KANTE
* <p>
*		Header file of game build
* </p>
*/
#ifndef GAME_H
#define GAME_H

#include "stdio.h"
#include "stdlib.h"

struct GAME{
	double tableBalance;
	double maxBalance;
	char* theRichestPerson;
	void (*run)(struct GAME*);
	void(*delete_Game)(struct GAME*);	
	
};

typedef struct GAME* Game;

Game new_Game();

void run(const Game);
void delete_Game(const Game);


#endif