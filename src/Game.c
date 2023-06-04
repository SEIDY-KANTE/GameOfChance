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

void findTheRichestPerson(const File this, const Game gameKing){
	 gameKing->maxBalance=this->person[0]->money;
	 char* theRichest=this->person[0]->name;
	int i=0;
	for(i; i<this->numberOfPerson; i++){
		if(gameKing->maxBalance < this->person[i]->money){
			gameKing->maxBalance=this->person[i]->money;
			gameKing->theRichestPerson=this->person[i]->name;
		}		
	}
}

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
				findTheRichestPerson(inMyFile,this);	
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


////Display to console

void draw(int luckyNumber, int round, double tableBalance ,char* theRichestPerson, double balance){
	system("cls");
    printf("%90s\n","############################################################");
    printf("%32s %31s %d %20s\n","##","LUCKY NUMBER:",luckyNumber,"\t##");
    printf("%90s\n","############################################################");
    printf("%90s\n","############################################################");
    printf("%32s %23s %d %15s\n","##","ROUND:",round,"\t\t\t##");
    printf("%32s %20s %0.0lf TL %21s\n","##","TABLE BALANCE:",tableBalance,"\t##");
    printf("%32s %32s %23s\n","##","","\t##");
    printf("%90s\n","##--------------------------------------------------------##");
	printf("%32s %32s %10s\n","##","THE RICHEST PERSON","\t\t\t##");
    printf("%32s %32s %10s\n","##",theRichestPerson,"\t\t\t##");
    printf("%32s %17s %0.0lf %27s\n","##","BALANCE:",balance,"\t##");
    printf("%32s %32s %23s\n","##","","\t##");
    printf("%90s\n","############################################################");
	sleep(1);
}

void drawGameOver(int round, double tableBalance){
	system("cls");
	printf("%90s\n","############################################################");
    printf("%32s %23s %d %15s\n","##","ROUND:",round,"\t\t\t##");
    printf("%32s %20s %0.0lf TL %21s\n","##","TABLE BALANCE:",tableBalance,"\t##");
    printf("%32s %32s %23s\n","##","","\t##");
    printf("%90s\n","##--------------------------------------------------------##");
	printf("%32s %32s %10s\n","##","GAME OVER","\t\t\t##");
    printf("%32s %32s %10s\n","##","","\t\t\t##");
    printf("%32s %32s %23s\n","##","","\t##");
    printf("%32s %32s %23s\n","##","","\t##");
    printf("%90s\n","############################################################");
}