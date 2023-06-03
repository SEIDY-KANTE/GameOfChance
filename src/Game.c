/**
*
* @author SEIDY KANTE
* <p>
*		Implementation of game structure
* </p>
*/

#include "File.h"

typedef enum {false, true} boolean;

void draw(int luckyNumber, int round, double tableBalance,char* theRichestPerson, double balance);
void oyunBittiCiz(int round, double tableBalance);

Game new_Game(){
	Game this;
	this->tableBalance=0;

	double maxBalance=0;
	char* theRichestPerson;

	this=(Game)malloc(sizeof(struct GAME));
	
	this->run=&run;
	this->delete_Game=&delete_Game;
	
}
void delete_Game(const Game this){
	if(this==NULL) return;
	free(this);
}
