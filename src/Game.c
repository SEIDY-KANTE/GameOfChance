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
void drawGameOver(int round, double tableBalance);

Game new_Game(){
	Game this;
	this->tableBalance=0;

	double maxBalance=0;
	char* theRichestPerson;

	this=(Game)malloc(sizeof(struct GAME));
	
	this->run=&run;
	this->delete_Game=&delete_Game;
	
}

void run(const Game this){
	char* personFile="Person.txt";
	char* numbersFile="Numbers.txt";
	File inMyFile = new_File(personFile,numbersFile);

	int numberOfPerson=inMyFile->numberOfPerson;
	int roundNumber=inMyFile->roundNumber;

	inMyFile->readPersonFile(inMyFile, personFile);
	inMyFile->readNumbersFile(inMyFile, numbersFile);

	
	int numberOfPlayer=inMyFile->numberOfPerson;
	int losersPerRound=0;

	int i=0;
	boolean isGameOver;

	for(i; i<roundNumber; i++){
		int j=0;
		
		isGameOver = true;
		for(j; j<numberOfPerson; j++)
		{			
			if(inMyFile->person[j]->money>=1000.0){
				inMyFile->person[j]->play(inMyFile->person[j],this,inMyFile->numbers[i]);
				//Here Find the richest person
				isGameOver=false;
			}
			
		}

		if(isGameOver) break;
		
		draw(inMyFile->numbers[i],i+1,this->tableBalance,this->theRichestPerson,this->maxBalance);
	}	
	//drawGameOver(i,this->tableBalance);
}

void delete_Game(const Game this){
	if(this==NULL) return;
	free(this);
}
